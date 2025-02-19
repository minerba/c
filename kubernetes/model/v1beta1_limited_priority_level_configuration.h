/*
 * v1beta1_limited_priority_level_configuration.h
 *
 * LimitedPriorityLevelConfiguration specifies how to handle requests that are subject to limits. It addresses two issues:  * How are requests for this priority level limited?  * What should be done with requests that exceed the limit?
 */

#ifndef _v1beta1_limited_priority_level_configuration_H_
#define _v1beta1_limited_priority_level_configuration_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_limited_priority_level_configuration_t v1beta1_limited_priority_level_configuration_t;

#include "v1beta1_limit_response.h"



typedef struct v1beta1_limited_priority_level_configuration_t {
    int assured_concurrency_shares; //numeric
    struct v1beta1_limit_response_t *limit_response; //model

} v1beta1_limited_priority_level_configuration_t;

v1beta1_limited_priority_level_configuration_t *v1beta1_limited_priority_level_configuration_create(
    int assured_concurrency_shares,
    v1beta1_limit_response_t *limit_response
);

void v1beta1_limited_priority_level_configuration_free(v1beta1_limited_priority_level_configuration_t *v1beta1_limited_priority_level_configuration);

v1beta1_limited_priority_level_configuration_t *v1beta1_limited_priority_level_configuration_parseFromJSON(cJSON *v1beta1_limited_priority_level_configurationJSON);

cJSON *v1beta1_limited_priority_level_configuration_convertToJSON(v1beta1_limited_priority_level_configuration_t *v1beta1_limited_priority_level_configuration);

#endif /* _v1beta1_limited_priority_level_configuration_H_ */

