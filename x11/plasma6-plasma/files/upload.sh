#!/bin/sh

subdir="KDE/git/plasma6"
distfiles="$(make -VDISTDIR)"
remote_base="/home/kde/public_distfiles"
remote="freefall"

ssh ${remote} "mkdir -p ${remote_base}/${subdir}"
rsync -rulv ${distfiles}/${subdir}/*.tar.xz ${remote}:${remote_base}/${subdir}
