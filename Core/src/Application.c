#include "Application.h"

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

struct LsApplication_T {
	const char *pName;
	uint32_t version;
	uint32_t windowCount;
};

bool lsUpdateApplication(struct LsApplication_T *pApplication);

bool lsCreateInstance(struct LsApplication_T *pApplication, PFN_lsApplicationErrorCallback errorCallback);

void lsCreateApplication(LsApplicationCreateInfo *pCreateInfo, LsApplication *pApplication,
                         PFN_lsApplicationErrorCallback applicationErrorCallback) {
	struct LsApplication_T *result = malloc(sizeof(struct LsApplication_T));

	result->pName = pCreateInfo->pName;
	result->version = pCreateInfo->version;
	result->windowCount = 0;

	fprintf(stdout, "Created application: %s, version: %d.%d.%d", result->pName, GET_MAJOR_VERSION(result->version),
	        GET_MINOR_VERSION(result->version), GET_PATCH_VERSION(result->version));

	*pApplication = result;
}

void lsRunApplication(struct LsApplication_T *pApplication) {
	while (lsUpdateApplication(pApplication));
}

void lsDestroyApplication(LsApplication application) {
	free(application);
}

bool lsUpdateApplication(struct LsApplication_T *pApplication) {
	return true;
}
