#ifndef v1beta1_allowed_csi_driver_TEST
#define v1beta1_allowed_csi_driver_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta1_allowed_csi_driver_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta1_allowed_csi_driver.h"
v1beta1_allowed_csi_driver_t* instantiate_v1beta1_allowed_csi_driver(int include_optional);



v1beta1_allowed_csi_driver_t* instantiate_v1beta1_allowed_csi_driver(int include_optional) {
  v1beta1_allowed_csi_driver_t* v1beta1_allowed_csi_driver = NULL;
  if (include_optional) {
    v1beta1_allowed_csi_driver = v1beta1_allowed_csi_driver_create(
      "0"
    );
  } else {
    v1beta1_allowed_csi_driver = v1beta1_allowed_csi_driver_create(
      "0"
    );
  }

  return v1beta1_allowed_csi_driver;
}


#ifdef v1beta1_allowed_csi_driver_MAIN

void test_v1beta1_allowed_csi_driver(int include_optional) {
    v1beta1_allowed_csi_driver_t* v1beta1_allowed_csi_driver_1 = instantiate_v1beta1_allowed_csi_driver(include_optional);

	cJSON* jsonv1beta1_allowed_csi_driver_1 = v1beta1_allowed_csi_driver_convertToJSON(v1beta1_allowed_csi_driver_1);
	printf("v1beta1_allowed_csi_driver :\n%s\n", cJSON_Print(jsonv1beta1_allowed_csi_driver_1));
	v1beta1_allowed_csi_driver_t* v1beta1_allowed_csi_driver_2 = v1beta1_allowed_csi_driver_parseFromJSON(jsonv1beta1_allowed_csi_driver_1);
	cJSON* jsonv1beta1_allowed_csi_driver_2 = v1beta1_allowed_csi_driver_convertToJSON(v1beta1_allowed_csi_driver_2);
	printf("repeating v1beta1_allowed_csi_driver:\n%s\n", cJSON_Print(jsonv1beta1_allowed_csi_driver_2));
}

int main() {
  test_v1beta1_allowed_csi_driver(1);
  test_v1beta1_allowed_csi_driver(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta1_allowed_csi_driver_MAIN
#endif // v1beta1_allowed_csi_driver_TEST
