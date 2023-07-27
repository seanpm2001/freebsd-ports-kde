#!/bin/sh

base_url=https://invent.kde.org
list_file=https://invent.kde.org/sysadmin/ci-management/-/raw/master/qt6/plasma-latest.yml
version_file=$(dirname $0)/bsd.plasma6-version.mk


changed=0

echo "Checking out repostiories to ${checkout_base}"

echo "Fetching versions and creating tarballs"

echo "Recreationg ${version_file}"
echo "# KDE Plasma6 versions $(date)" > ${version_file}

checkout_base="$(make -VDISTDIR)/KDE/git/plasma6"
mkdir -p ${checkout_base}
repos=$(curl -Lks -q ${list_file} | grep -v '#' | awk -F : /master/'{print $1}' | sed 's|"||g')
components="_KDE_PLASMA6_COMPONENTS=	"
for repo in ${repos} ; do 
	repo_url=${base_url}/${repo}.git
	hash=$(git ls-remote ${repo_url} HEAD | awk '{print $1}')
	name=$(echo ${repo} | cut -d / -f 2)
	echo "_KDE_PLASMA6_HASH_${name}=	${hash}" >> ${version_file}

	components="${components}${name} "

	distname=plasma6-${name}-${hash}
	distfile=${checkout_base}/${distname}.tar.xz
	if [ ! -f ${distfile} ] ; then
		repo_dir=${checkout_base}/${name}
		if [ ! -d ${repo_dir} ] ; then
			git -C ${checkout_base} clone ${repo_url}
		else
			git -C ${repo_dir} checkout master && \
			git -C ${repo_dir} pull --ff-only --rebase --autostash
		fi
		version=$(git -C ${repo_dir} show -s --date=format:'%Y%m%d-%H%M' --format=%cd)
		echo "_KDE_PLASMA6_VERSION_${name}=		${version}" >> ${version_file}
		# ensure we're at the wanted hash
		git -C ${repo_dir} archive \
			--format=tar \
			--prefix=${distname}/ \
			${hash} | xz > ${distfile}
		echo "Created: ${distfile}"
		changed=1
	else
		echo "Existing: ${distfile}"
	fi
done

echo "${components}" >> ${version_file}
if [ $changed -eq 1 ] ; then 
	$(dirname 0)/upload.sh
fi
