#pragma once

#include "kmsvnc.h"

/* Panel orientation constants */
#define DRM_MODE_PANEL_ORIENTATION_NORMAL       0
#define DRM_MODE_PANEL_ORIENTATION_UPSIDE_DOWN  1
#define DRM_MODE_PANEL_ORIENTATION_LEFT_SIDE_UP 2
#define DRM_MODE_PANEL_ORIENTATION_RIGHT_SIDE_UP 3

#define DRM_IOCTL_MUST(...) do{ int e; if ((e = drmIoctl(__VA_ARGS__))) KMSVNC_FATAL("DRM ioctl error %d on line %d\n", e, __LINE__); } while(0)
#define DRM_IOCTL_MAY(...) do{ int e; if ((e = drmIoctl(__VA_ARGS__))) fprintf(stderr, "DRM ioctl error %d on line %d\n", e, __LINE__); } while(0)
#define DRM_R_IOCTL_MAY(...) do{ int e; if ((e = ioctl(__VA_ARGS__))) fprintf(stderr, "DRM ioctl error %d on line %d\n", e, __LINE__); } while(0)


void drm_cleanup();
int drm_open();
int drm_vendors();
int drm_dump_cursor_plane(char** data, int* width, int* height);

/* Dichiarazione del prototipo della funzione di rilevamento dell'orientamento */
static int detect_panel_orientation(int drm_fd, uint32_t crtc_id);

/* Funzioni di rotazione dell'immagine */
static void rotate_90_clockwise(const char* in, int width, int height, char* buff);
static void rotate_90_counterclockwise(const char* in, int width, int height, char* buff);
static void rotate_180(const char* in, int width, int height, char* buff);

/* Nuove funzioni di conversione con orientamento */
static void convert_bgra_to_rgba_with_orientation(const char* in, int width, int height, char* buff);
static void convert_vaapi_with_orientation(const char* in, int width, int height, char* buff);
static inline void convert_x_tiled_with_orientation(const int tilex, const int tiley, const char* in, int width, int height, char* buff);