--- src/3rdparty/chromium/third_party/webrtc/modules/video_coding/codecs/h264/h264_decoder_impl.cc.orig	2021-11-25 09:20:12 UTC
+++ src/3rdparty/chromium/third_party/webrtc/modules/video_coding/codecs/h264/h264_decoder_impl.cc
@@ -202,6 +202,9 @@ int32_t H264DecoderImpl::InitDecode(const VideoCodec* 
   // a pointer |this|.
   av_context_->opaque = this;
 
+  // Initializing |lowres|
+  av_context_->lowres = 0;
+
   AVCodec* codec = avcodec_find_decoder(av_context_->codec_id);
   if (!codec) {
     // This is an indication that FFmpeg has not been initialized or it has not
