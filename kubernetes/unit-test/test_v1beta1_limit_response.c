#ifndef v1beta1_limit_response_TEST
#define v1beta1_limit_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta1_limit_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta1_limit_response.h"
v1beta1_limit_response_t* instantiate_v1beta1_limit_response(int include_optional);

#include "test_v1beta1_queuing_configuration.c"


v1beta1_limit_response_t* instantiate_v1beta1_limit_response(int include_optional) {
  v1beta1_limit_response_t* v1beta1_limit_response = NULL;
  if (include_optional) {
    v1beta1_limit_response = v1beta1_limit_response_create(
       // false, not to have infinite recursion
      instantiate_v1beta1_queuing_configuration(0),
      "0"
    );
  } else {
    v1beta1_limit_response = v1beta1_limit_response_create(
      NULL,
      "0"
    );
  }

  return v1beta1_limit_response;
}


#ifdef v1beta1_limit_response_MAIN

void test_v1beta1_limit_response(int include_optional) {
    v1beta1_limit_response_t* v1beta1_limit_response_1 = instantiate_v1beta1_limit_response(include_optional);

	cJSON* jsonv1beta1_limit_response_1 = v1beta1_limit_response_convertToJSON(v1beta1_limit_response_1);
	printf("v1beta1_limit_response :\n%s\n", cJSON_Print(jsonv1beta1_limit_response_1));
	v1beta1_limit_response_t* v1beta1_limit_response_2 = v1beta1_limit_response_parseFromJSON(jsonv1beta1_limit_response_1);
	cJSON* jsonv1beta1_limit_response_2 = v1beta1_limit_response_convertToJSON(v1beta1_limit_response_2);
	printf("repeating v1beta1_limit_response:\n%s\n", cJSON_Print(jsonv1beta1_limit_response_2));
}

int main() {
  test_v1beta1_limit_response(1);
  test_v1beta1_limit_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta1_limit_response_MAIN
#endif // v1beta1_limit_response_TEST
