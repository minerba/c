/*
 * v1beta1_flow_schema_spec.h
 *
 * FlowSchemaSpec describes how the FlowSchema&#39;s specification looks like.
 */

#ifndef _v1beta1_flow_schema_spec_H_
#define _v1beta1_flow_schema_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_flow_schema_spec_t v1beta1_flow_schema_spec_t;

#include "v1beta1_flow_distinguisher_method.h"
#include "v1beta1_policy_rules_with_subjects.h"
#include "v1beta1_priority_level_configuration_reference.h"



typedef struct v1beta1_flow_schema_spec_t {
    struct v1beta1_flow_distinguisher_method_t *distinguisher_method; //model
    int matching_precedence; //numeric
    struct v1beta1_priority_level_configuration_reference_t *priority_level_configuration; //model
    list_t *rules; //nonprimitive container

} v1beta1_flow_schema_spec_t;

v1beta1_flow_schema_spec_t *v1beta1_flow_schema_spec_create(
    v1beta1_flow_distinguisher_method_t *distinguisher_method,
    int matching_precedence,
    v1beta1_priority_level_configuration_reference_t *priority_level_configuration,
    list_t *rules
);

void v1beta1_flow_schema_spec_free(v1beta1_flow_schema_spec_t *v1beta1_flow_schema_spec);

v1beta1_flow_schema_spec_t *v1beta1_flow_schema_spec_parseFromJSON(cJSON *v1beta1_flow_schema_specJSON);

cJSON *v1beta1_flow_schema_spec_convertToJSON(v1beta1_flow_schema_spec_t *v1beta1_flow_schema_spec);

#endif /* _v1beta1_flow_schema_spec_H_ */

