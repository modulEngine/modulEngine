#ifndef APPLICATION_H_
#define APPLICATION_H_

// std
#include <stdint.h>

#define CREATE_APPLICATION_VERSION(major, minor, patch) ((uint32_t)(major) << 24 | (uint32_t)(minor) << 12 | (uint32_t)(patch))
#define GET_MAJOR_VERSION(version) (((version) >> 24) & 0xFF)
#define GET_MINOR_VERSION(version) (((version) >> 12) & 0xFFF)
#define GET_PATCH_VERSION(version) ((version) & 0xFFF)

typedef struct LsApplication_T *LsApplication;

typedef struct {
	const char *pName;
	uint32_t version;
} LsApplicationCreateInfo;

typedef void (PFN_lsApplicationErrorCallback(const char *errorMessage));

void lsCreateApplication(LsApplicationCreateInfo *pCreateInfo,
                         LsApplication *pApplication,
                         PFN_lsApplicationErrorCallback applicationErrorCallback);
void lsRunApplication(LsApplication application);
void lsDestroyApplication(LsApplication application);

#endif //APPLICATION_H_
