#ifndef v1_job_status_TEST
#define v1_job_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_job_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_job_status.h"
v1_job_status_t* instantiate_v1_job_status(int include_optional);

#include "test_v1_uncounted_terminated_pods.c"


v1_job_status_t* instantiate_v1_job_status(int include_optional) {
  v1_job_status_t* v1_job_status = NULL;
  if (include_optional) {
    v1_job_status = v1_job_status_create(
      56,
      "0",
      "2013-10-20T19:20:30+01:00",
      list_createList(),
      56,
      56,
      "2013-10-20T19:20:30+01:00",
      56,
       // false, not to have infinite recursion
      instantiate_v1_uncounted_terminated_pods(0)
    );
  } else {
    v1_job_status = v1_job_status_create(
      56,
      "0",
      "2013-10-20T19:20:30+01:00",
      list_createList(),
      56,
      56,
      "2013-10-20T19:20:30+01:00",
      56,
      NULL
    );
  }

  return v1_job_status;
}


#ifdef v1_job_status_MAIN

void test_v1_job_status(int include_optional) {
    v1_job_status_t* v1_job_status_1 = instantiate_v1_job_status(include_optional);

	cJSON* jsonv1_job_status_1 = v1_job_status_convertToJSON(v1_job_status_1);
	printf("v1_job_status :\n%s\n", cJSON_Print(jsonv1_job_status_1));
	v1_job_status_t* v1_job_status_2 = v1_job_status_parseFromJSON(jsonv1_job_status_1);
	cJSON* jsonv1_job_status_2 = v1_job_status_convertToJSON(v1_job_status_2);
	printf("repeating v1_job_status:\n%s\n", cJSON_Print(jsonv1_job_status_2));
}

int main() {
  test_v1_job_status(1);
  test_v1_job_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_job_status_MAIN
#endif // v1_job_status_TEST
