#pragma once

#include "kmsvnc.h"
// Define panel orientation values as per the DRM documentation
#define DRM_MODE_PANEL_ORIENTATION_NORMAL   0
#define DRM_MODE_PANEL_ORIENTATION_UPSIDE_DOWN  1
#define DRM_MODE_PANEL_ORIENTATION_LEFT_SIDE_UP 2
#define DRM_MODE_PANEL_ORIENTATION_RIGHT_SIDE_UP 3

#define DRM_IOCTL_MUST(...) do{ int e; if ((e = drmIoctl(__VA_ARGS__))) KMSVNC_FATAL("DRM ioctl error %d on line %d\n", e, __LINE__); } while(0)
#define DRM_IOCTL_MAY(...) do{ int e; if ((e = drmIoctl(__VA_ARGS__))) fprintf(stderr, "DRM ioctl error %d on line %d\n", e, __LINE__); } while(0)
#define DRM_R_IOCTL_MAY(...) do{ int e; if ((e = ioctl(__VA_ARGS__))) fprintf(stderr, "DRM ioctl error %d on line %d\n", e, __LINE__); } while(0)


void drm_cleanup();
int drm_open();
int drm_vendors();
int drm_dump_cursor_plane(char **data, int *width, int *height);
