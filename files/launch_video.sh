#!/bin/bash  
echo "This is a shell script 1"  
gst-launch-1.0 filesrc location="WFovBaslerSwiftAlpha.mp4" ! qtdemux ! avdec_mpeg4 ! jpegenc ! rtpjpegpay ! udpsink host=225.1.1.1 port=5006 auto-multicast=true multicast-iface="enp59s0"

