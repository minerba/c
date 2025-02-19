#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_pod_security_policy_spec.h"



v1beta1_pod_security_policy_spec_t *v1beta1_pod_security_policy_spec_create(
    int allow_privilege_escalation,
    list_t *allowed_csi_drivers,
    list_t *allowed_capabilities,
    list_t *allowed_flex_volumes,
    list_t *allowed_host_paths,
    list_t *allowed_proc_mount_types,
    list_t *allowed_unsafe_sysctls,
    list_t *default_add_capabilities,
    int default_allow_privilege_escalation,
    list_t *forbidden_sysctls,
    v1beta1_fs_group_strategy_options_t *fs_group,
    int host_ipc,
    int host_network,
    int host_pid,
    list_t *host_ports,
    int privileged,
    int read_only_root_filesystem,
    list_t *required_drop_capabilities,
    v1beta1_run_as_group_strategy_options_t *run_as_group,
    v1beta1_run_as_user_strategy_options_t *run_as_user,
    v1beta1_runtime_class_strategy_options_t *runtime_class,
    v1beta1_se_linux_strategy_options_t *se_linux,
    v1beta1_supplemental_groups_strategy_options_t *supplemental_groups,
    list_t *volumes
    ) {
    v1beta1_pod_security_policy_spec_t *v1beta1_pod_security_policy_spec_local_var = malloc(sizeof(v1beta1_pod_security_policy_spec_t));
    if (!v1beta1_pod_security_policy_spec_local_var) {
        return NULL;
    }
    v1beta1_pod_security_policy_spec_local_var->allow_privilege_escalation = allow_privilege_escalation;
    v1beta1_pod_security_policy_spec_local_var->allowed_csi_drivers = allowed_csi_drivers;
    v1beta1_pod_security_policy_spec_local_var->allowed_capabilities = allowed_capabilities;
    v1beta1_pod_security_policy_spec_local_var->allowed_flex_volumes = allowed_flex_volumes;
    v1beta1_pod_security_policy_spec_local_var->allowed_host_paths = allowed_host_paths;
    v1beta1_pod_security_policy_spec_local_var->allowed_proc_mount_types = allowed_proc_mount_types;
    v1beta1_pod_security_policy_spec_local_var->allowed_unsafe_sysctls = allowed_unsafe_sysctls;
    v1beta1_pod_security_policy_spec_local_var->default_add_capabilities = default_add_capabilities;
    v1beta1_pod_security_policy_spec_local_var->default_allow_privilege_escalation = default_allow_privilege_escalation;
    v1beta1_pod_security_policy_spec_local_var->forbidden_sysctls = forbidden_sysctls;
    v1beta1_pod_security_policy_spec_local_var->fs_group = fs_group;
    v1beta1_pod_security_policy_spec_local_var->host_ipc = host_ipc;
    v1beta1_pod_security_policy_spec_local_var->host_network = host_network;
    v1beta1_pod_security_policy_spec_local_var->host_pid = host_pid;
    v1beta1_pod_security_policy_spec_local_var->host_ports = host_ports;
    v1beta1_pod_security_policy_spec_local_var->privileged = privileged;
    v1beta1_pod_security_policy_spec_local_var->read_only_root_filesystem = read_only_root_filesystem;
    v1beta1_pod_security_policy_spec_local_var->required_drop_capabilities = required_drop_capabilities;
    v1beta1_pod_security_policy_spec_local_var->run_as_group = run_as_group;
    v1beta1_pod_security_policy_spec_local_var->run_as_user = run_as_user;
    v1beta1_pod_security_policy_spec_local_var->runtime_class = runtime_class;
    v1beta1_pod_security_policy_spec_local_var->se_linux = se_linux;
    v1beta1_pod_security_policy_spec_local_var->supplemental_groups = supplemental_groups;
    v1beta1_pod_security_policy_spec_local_var->volumes = volumes;

    return v1beta1_pod_security_policy_spec_local_var;
}


void v1beta1_pod_security_policy_spec_free(v1beta1_pod_security_policy_spec_t *v1beta1_pod_security_policy_spec) {
    if(NULL == v1beta1_pod_security_policy_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_pod_security_policy_spec->allowed_csi_drivers) {
        list_ForEach(listEntry, v1beta1_pod_security_policy_spec->allowed_csi_drivers) {
            v1beta1_allowed_csi_driver_free(listEntry->data);
        }
        list_freeList(v1beta1_pod_security_policy_spec->allowed_csi_drivers);
        v1beta1_pod_security_policy_spec->allowed_csi_drivers = NULL;
    }
    if (v1beta1_pod_security_policy_spec->allowed_capabilities) {
        list_ForEach(listEntry, v1beta1_pod_security_policy_spec->allowed_capabilities) {
            free(listEntry->data);
        }
        list_freeList(v1beta1_pod_security_policy_spec->allowed_capabilities);
        v1beta1_pod_security_policy_spec->allowed_capabilities = NULL;
    }
    if (v1beta1_pod_security_policy_spec->allowed_flex_volumes) {
        list_ForEach(listEntry, v1beta1_pod_security_policy_spec->allowed_flex_volumes) {
            v1beta1_allowed_flex_volume_free(listEntry->data);
        }
        list_freeList(v1beta1_pod_security_policy_spec->allowed_flex_volumes);
        v1beta1_pod_security_policy_spec->allowed_flex_volumes = NULL;
    }
    if (v1beta1_pod_security_policy_spec->allowed_host_paths) {
        list_ForEach(listEntry, v1beta1_pod_security_policy_spec->allowed_host_paths) {
            v1beta1_allowed_host_path_free(listEntry->data);
        }
        list_freeList(v1beta1_pod_security_policy_spec->allowed_host_paths);
        v1beta1_pod_security_policy_spec->allowed_host_paths = NULL;
    }
    if (v1beta1_pod_security_policy_spec->allowed_proc_mount_types) {
        list_ForEach(listEntry, v1beta1_pod_security_policy_spec->allowed_proc_mount_types) {
            free(listEntry->data);
        }
        list_freeList(v1beta1_pod_security_policy_spec->allowed_proc_mount_types);
        v1beta1_pod_security_policy_spec->allowed_proc_mount_types = NULL;
    }
    if (v1beta1_pod_security_policy_spec->allowed_unsafe_sysctls) {
        list_ForEach(listEntry, v1beta1_pod_security_policy_spec->allowed_unsafe_sysctls) {
            free(listEntry->data);
        }
        list_freeList(v1beta1_pod_security_policy_spec->allowed_unsafe_sysctls);
        v1beta1_pod_security_policy_spec->allowed_unsafe_sysctls = NULL;
    }
    if (v1beta1_pod_security_policy_spec->default_add_capabilities) {
        list_ForEach(listEntry, v1beta1_pod_security_policy_spec->default_add_capabilities) {
            free(listEntry->data);
        }
        list_freeList(v1beta1_pod_security_policy_spec->default_add_capabilities);
        v1beta1_pod_security_policy_spec->default_add_capabilities = NULL;
    }
    if (v1beta1_pod_security_policy_spec->forbidden_sysctls) {
        list_ForEach(listEntry, v1beta1_pod_security_policy_spec->forbidden_sysctls) {
            free(listEntry->data);
        }
        list_freeList(v1beta1_pod_security_policy_spec->forbidden_sysctls);
        v1beta1_pod_security_policy_spec->forbidden_sysctls = NULL;
    }
    if (v1beta1_pod_security_policy_spec->fs_group) {
        v1beta1_fs_group_strategy_options_free(v1beta1_pod_security_policy_spec->fs_group);
        v1beta1_pod_security_policy_spec->fs_group = NULL;
    }
    if (v1beta1_pod_security_policy_spec->host_ports) {
        list_ForEach(listEntry, v1beta1_pod_security_policy_spec->host_ports) {
            v1beta1_host_port_range_free(listEntry->data);
        }
        list_freeList(v1beta1_pod_security_policy_spec->host_ports);
        v1beta1_pod_security_policy_spec->host_ports = NULL;
    }
    if (v1beta1_pod_security_policy_spec->required_drop_capabilities) {
        list_ForEach(listEntry, v1beta1_pod_security_policy_spec->required_drop_capabilities) {
            free(listEntry->data);
        }
        list_freeList(v1beta1_pod_security_policy_spec->required_drop_capabilities);
        v1beta1_pod_security_policy_spec->required_drop_capabilities = NULL;
    }
    if (v1beta1_pod_security_policy_spec->run_as_group) {
        v1beta1_run_as_group_strategy_options_free(v1beta1_pod_security_policy_spec->run_as_group);
        v1beta1_pod_security_policy_spec->run_as_group = NULL;
    }
    if (v1beta1_pod_security_policy_spec->run_as_user) {
        v1beta1_run_as_user_strategy_options_free(v1beta1_pod_security_policy_spec->run_as_user);
        v1beta1_pod_security_policy_spec->run_as_user = NULL;
    }
    if (v1beta1_pod_security_policy_spec->runtime_class) {
        v1beta1_runtime_class_strategy_options_free(v1beta1_pod_security_policy_spec->runtime_class);
        v1beta1_pod_security_policy_spec->runtime_class = NULL;
    }
    if (v1beta1_pod_security_policy_spec->se_linux) {
        v1beta1_se_linux_strategy_options_free(v1beta1_pod_security_policy_spec->se_linux);
        v1beta1_pod_security_policy_spec->se_linux = NULL;
    }
    if (v1beta1_pod_security_policy_spec->supplemental_groups) {
        v1beta1_supplemental_groups_strategy_options_free(v1beta1_pod_security_policy_spec->supplemental_groups);
        v1beta1_pod_security_policy_spec->supplemental_groups = NULL;
    }
    if (v1beta1_pod_security_policy_spec->volumes) {
        list_ForEach(listEntry, v1beta1_pod_security_policy_spec->volumes) {
            free(listEntry->data);
        }
        list_freeList(v1beta1_pod_security_policy_spec->volumes);
        v1beta1_pod_security_policy_spec->volumes = NULL;
    }
    free(v1beta1_pod_security_policy_spec);
}

cJSON *v1beta1_pod_security_policy_spec_convertToJSON(v1beta1_pod_security_policy_spec_t *v1beta1_pod_security_policy_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_pod_security_policy_spec->allow_privilege_escalation
    if(v1beta1_pod_security_policy_spec->allow_privilege_escalation) {
    if(cJSON_AddBoolToObject(item, "allowPrivilegeEscalation", v1beta1_pod_security_policy_spec->allow_privilege_escalation) == NULL) {
    goto fail; //Bool
    }
    }


    // v1beta1_pod_security_policy_spec->allowed_csi_drivers
    if(v1beta1_pod_security_policy_spec->allowed_csi_drivers) {
    cJSON *allowed_csi_drivers = cJSON_AddArrayToObject(item, "allowedCSIDrivers");
    if(allowed_csi_drivers == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *allowed_csi_driversListEntry;
    if (v1beta1_pod_security_policy_spec->allowed_csi_drivers) {
    list_ForEach(allowed_csi_driversListEntry, v1beta1_pod_security_policy_spec->allowed_csi_drivers) {
    cJSON *itemLocal = v1beta1_allowed_csi_driver_convertToJSON(allowed_csi_driversListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(allowed_csi_drivers, itemLocal);
    }
    }
    }


    // v1beta1_pod_security_policy_spec->allowed_capabilities
    if(v1beta1_pod_security_policy_spec->allowed_capabilities) {
    cJSON *allowed_capabilities = cJSON_AddArrayToObject(item, "allowedCapabilities");
    if(allowed_capabilities == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *allowed_capabilitiesListEntry;
    list_ForEach(allowed_capabilitiesListEntry, v1beta1_pod_security_policy_spec->allowed_capabilities) {
    if(cJSON_AddStringToObject(allowed_capabilities, "", (char*)allowed_capabilitiesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1beta1_pod_security_policy_spec->allowed_flex_volumes
    if(v1beta1_pod_security_policy_spec->allowed_flex_volumes) {
    cJSON *allowed_flex_volumes = cJSON_AddArrayToObject(item, "allowedFlexVolumes");
    if(allowed_flex_volumes == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *allowed_flex_volumesListEntry;
    if (v1beta1_pod_security_policy_spec->allowed_flex_volumes) {
    list_ForEach(allowed_flex_volumesListEntry, v1beta1_pod_security_policy_spec->allowed_flex_volumes) {
    cJSON *itemLocal = v1beta1_allowed_flex_volume_convertToJSON(allowed_flex_volumesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(allowed_flex_volumes, itemLocal);
    }
    }
    }


    // v1beta1_pod_security_policy_spec->allowed_host_paths
    if(v1beta1_pod_security_policy_spec->allowed_host_paths) {
    cJSON *allowed_host_paths = cJSON_AddArrayToObject(item, "allowedHostPaths");
    if(allowed_host_paths == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *allowed_host_pathsListEntry;
    if (v1beta1_pod_security_policy_spec->allowed_host_paths) {
    list_ForEach(allowed_host_pathsListEntry, v1beta1_pod_security_policy_spec->allowed_host_paths) {
    cJSON *itemLocal = v1beta1_allowed_host_path_convertToJSON(allowed_host_pathsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(allowed_host_paths, itemLocal);
    }
    }
    }


    // v1beta1_pod_security_policy_spec->allowed_proc_mount_types
    if(v1beta1_pod_security_policy_spec->allowed_proc_mount_types) {
    cJSON *allowed_proc_mount_types = cJSON_AddArrayToObject(item, "allowedProcMountTypes");
    if(allowed_proc_mount_types == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *allowed_proc_mount_typesListEntry;
    list_ForEach(allowed_proc_mount_typesListEntry, v1beta1_pod_security_policy_spec->allowed_proc_mount_types) {
    if(cJSON_AddStringToObject(allowed_proc_mount_types, "", (char*)allowed_proc_mount_typesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1beta1_pod_security_policy_spec->allowed_unsafe_sysctls
    if(v1beta1_pod_security_policy_spec->allowed_unsafe_sysctls) {
    cJSON *allowed_unsafe_sysctls = cJSON_AddArrayToObject(item, "allowedUnsafeSysctls");
    if(allowed_unsafe_sysctls == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *allowed_unsafe_sysctlsListEntry;
    list_ForEach(allowed_unsafe_sysctlsListEntry, v1beta1_pod_security_policy_spec->allowed_unsafe_sysctls) {
    if(cJSON_AddStringToObject(allowed_unsafe_sysctls, "", (char*)allowed_unsafe_sysctlsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1beta1_pod_security_policy_spec->default_add_capabilities
    if(v1beta1_pod_security_policy_spec->default_add_capabilities) {
    cJSON *default_add_capabilities = cJSON_AddArrayToObject(item, "defaultAddCapabilities");
    if(default_add_capabilities == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *default_add_capabilitiesListEntry;
    list_ForEach(default_add_capabilitiesListEntry, v1beta1_pod_security_policy_spec->default_add_capabilities) {
    if(cJSON_AddStringToObject(default_add_capabilities, "", (char*)default_add_capabilitiesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1beta1_pod_security_policy_spec->default_allow_privilege_escalation
    if(v1beta1_pod_security_policy_spec->default_allow_privilege_escalation) {
    if(cJSON_AddBoolToObject(item, "defaultAllowPrivilegeEscalation", v1beta1_pod_security_policy_spec->default_allow_privilege_escalation) == NULL) {
    goto fail; //Bool
    }
    }


    // v1beta1_pod_security_policy_spec->forbidden_sysctls
    if(v1beta1_pod_security_policy_spec->forbidden_sysctls) {
    cJSON *forbidden_sysctls = cJSON_AddArrayToObject(item, "forbiddenSysctls");
    if(forbidden_sysctls == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *forbidden_sysctlsListEntry;
    list_ForEach(forbidden_sysctlsListEntry, v1beta1_pod_security_policy_spec->forbidden_sysctls) {
    if(cJSON_AddStringToObject(forbidden_sysctls, "", (char*)forbidden_sysctlsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1beta1_pod_security_policy_spec->fs_group
    if (!v1beta1_pod_security_policy_spec->fs_group) {
        goto fail;
    }
    cJSON *fs_group_local_JSON = v1beta1_fs_group_strategy_options_convertToJSON(v1beta1_pod_security_policy_spec->fs_group);
    if(fs_group_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "fsGroup", fs_group_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // v1beta1_pod_security_policy_spec->host_ipc
    if(v1beta1_pod_security_policy_spec->host_ipc) {
    if(cJSON_AddBoolToObject(item, "hostIPC", v1beta1_pod_security_policy_spec->host_ipc) == NULL) {
    goto fail; //Bool
    }
    }


    // v1beta1_pod_security_policy_spec->host_network
    if(v1beta1_pod_security_policy_spec->host_network) {
    if(cJSON_AddBoolToObject(item, "hostNetwork", v1beta1_pod_security_policy_spec->host_network) == NULL) {
    goto fail; //Bool
    }
    }


    // v1beta1_pod_security_policy_spec->host_pid
    if(v1beta1_pod_security_policy_spec->host_pid) {
    if(cJSON_AddBoolToObject(item, "hostPID", v1beta1_pod_security_policy_spec->host_pid) == NULL) {
    goto fail; //Bool
    }
    }


    // v1beta1_pod_security_policy_spec->host_ports
    if(v1beta1_pod_security_policy_spec->host_ports) {
    cJSON *host_ports = cJSON_AddArrayToObject(item, "hostPorts");
    if(host_ports == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *host_portsListEntry;
    if (v1beta1_pod_security_policy_spec->host_ports) {
    list_ForEach(host_portsListEntry, v1beta1_pod_security_policy_spec->host_ports) {
    cJSON *itemLocal = v1beta1_host_port_range_convertToJSON(host_portsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(host_ports, itemLocal);
    }
    }
    }


    // v1beta1_pod_security_policy_spec->privileged
    if(v1beta1_pod_security_policy_spec->privileged) {
    if(cJSON_AddBoolToObject(item, "privileged", v1beta1_pod_security_policy_spec->privileged) == NULL) {
    goto fail; //Bool
    }
    }


    // v1beta1_pod_security_policy_spec->read_only_root_filesystem
    if(v1beta1_pod_security_policy_spec->read_only_root_filesystem) {
    if(cJSON_AddBoolToObject(item, "readOnlyRootFilesystem", v1beta1_pod_security_policy_spec->read_only_root_filesystem) == NULL) {
    goto fail; //Bool
    }
    }


    // v1beta1_pod_security_policy_spec->required_drop_capabilities
    if(v1beta1_pod_security_policy_spec->required_drop_capabilities) {
    cJSON *required_drop_capabilities = cJSON_AddArrayToObject(item, "requiredDropCapabilities");
    if(required_drop_capabilities == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *required_drop_capabilitiesListEntry;
    list_ForEach(required_drop_capabilitiesListEntry, v1beta1_pod_security_policy_spec->required_drop_capabilities) {
    if(cJSON_AddStringToObject(required_drop_capabilities, "", (char*)required_drop_capabilitiesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1beta1_pod_security_policy_spec->run_as_group
    if(v1beta1_pod_security_policy_spec->run_as_group) {
    cJSON *run_as_group_local_JSON = v1beta1_run_as_group_strategy_options_convertToJSON(v1beta1_pod_security_policy_spec->run_as_group);
    if(run_as_group_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "runAsGroup", run_as_group_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1beta1_pod_security_policy_spec->run_as_user
    if (!v1beta1_pod_security_policy_spec->run_as_user) {
        goto fail;
    }
    cJSON *run_as_user_local_JSON = v1beta1_run_as_user_strategy_options_convertToJSON(v1beta1_pod_security_policy_spec->run_as_user);
    if(run_as_user_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "runAsUser", run_as_user_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // v1beta1_pod_security_policy_spec->runtime_class
    if(v1beta1_pod_security_policy_spec->runtime_class) {
    cJSON *runtime_class_local_JSON = v1beta1_runtime_class_strategy_options_convertToJSON(v1beta1_pod_security_policy_spec->runtime_class);
    if(runtime_class_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "runtimeClass", runtime_class_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1beta1_pod_security_policy_spec->se_linux
    if (!v1beta1_pod_security_policy_spec->se_linux) {
        goto fail;
    }
    cJSON *se_linux_local_JSON = v1beta1_se_linux_strategy_options_convertToJSON(v1beta1_pod_security_policy_spec->se_linux);
    if(se_linux_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "seLinux", se_linux_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // v1beta1_pod_security_policy_spec->supplemental_groups
    if (!v1beta1_pod_security_policy_spec->supplemental_groups) {
        goto fail;
    }
    cJSON *supplemental_groups_local_JSON = v1beta1_supplemental_groups_strategy_options_convertToJSON(v1beta1_pod_security_policy_spec->supplemental_groups);
    if(supplemental_groups_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "supplementalGroups", supplemental_groups_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // v1beta1_pod_security_policy_spec->volumes
    if(v1beta1_pod_security_policy_spec->volumes) {
    cJSON *volumes = cJSON_AddArrayToObject(item, "volumes");
    if(volumes == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *volumesListEntry;
    list_ForEach(volumesListEntry, v1beta1_pod_security_policy_spec->volumes) {
    if(cJSON_AddStringToObject(volumes, "", (char*)volumesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1beta1_pod_security_policy_spec_t *v1beta1_pod_security_policy_spec_parseFromJSON(cJSON *v1beta1_pod_security_policy_specJSON){

    v1beta1_pod_security_policy_spec_t *v1beta1_pod_security_policy_spec_local_var = NULL;

    // define the local list for v1beta1_pod_security_policy_spec->allowed_csi_drivers
    list_t *allowed_csi_driversList = NULL;

    // define the local list for v1beta1_pod_security_policy_spec->allowed_capabilities
    list_t *allowed_capabilitiesList = NULL;

    // define the local list for v1beta1_pod_security_policy_spec->allowed_flex_volumes
    list_t *allowed_flex_volumesList = NULL;

    // define the local list for v1beta1_pod_security_policy_spec->allowed_host_paths
    list_t *allowed_host_pathsList = NULL;

    // define the local list for v1beta1_pod_security_policy_spec->allowed_proc_mount_types
    list_t *allowed_proc_mount_typesList = NULL;

    // define the local list for v1beta1_pod_security_policy_spec->allowed_unsafe_sysctls
    list_t *allowed_unsafe_sysctlsList = NULL;

    // define the local list for v1beta1_pod_security_policy_spec->default_add_capabilities
    list_t *default_add_capabilitiesList = NULL;

    // define the local list for v1beta1_pod_security_policy_spec->forbidden_sysctls
    list_t *forbidden_sysctlsList = NULL;

    // define the local variable for v1beta1_pod_security_policy_spec->fs_group
    v1beta1_fs_group_strategy_options_t *fs_group_local_nonprim = NULL;

    // define the local list for v1beta1_pod_security_policy_spec->host_ports
    list_t *host_portsList = NULL;

    // define the local list for v1beta1_pod_security_policy_spec->required_drop_capabilities
    list_t *required_drop_capabilitiesList = NULL;

    // define the local variable for v1beta1_pod_security_policy_spec->run_as_group
    v1beta1_run_as_group_strategy_options_t *run_as_group_local_nonprim = NULL;

    // define the local variable for v1beta1_pod_security_policy_spec->run_as_user
    v1beta1_run_as_user_strategy_options_t *run_as_user_local_nonprim = NULL;

    // define the local variable for v1beta1_pod_security_policy_spec->runtime_class
    v1beta1_runtime_class_strategy_options_t *runtime_class_local_nonprim = NULL;

    // define the local variable for v1beta1_pod_security_policy_spec->se_linux
    v1beta1_se_linux_strategy_options_t *se_linux_local_nonprim = NULL;

    // define the local variable for v1beta1_pod_security_policy_spec->supplemental_groups
    v1beta1_supplemental_groups_strategy_options_t *supplemental_groups_local_nonprim = NULL;

    // define the local list for v1beta1_pod_security_policy_spec->volumes
    list_t *volumesList = NULL;

    // v1beta1_pod_security_policy_spec->allow_privilege_escalation
    cJSON *allow_privilege_escalation = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_security_policy_specJSON, "allowPrivilegeEscalation");
    if (allow_privilege_escalation) { 
    if(!cJSON_IsBool(allow_privilege_escalation))
    {
    goto end; //Bool
    }
    }

    // v1beta1_pod_security_policy_spec->allowed_csi_drivers
    cJSON *allowed_csi_drivers = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_security_policy_specJSON, "allowedCSIDrivers");
    if (allowed_csi_drivers) { 
    cJSON *allowed_csi_drivers_local_nonprimitive = NULL;
    if(!cJSON_IsArray(allowed_csi_drivers)){
        goto end; //nonprimitive container
    }

    allowed_csi_driversList = list_createList();

    cJSON_ArrayForEach(allowed_csi_drivers_local_nonprimitive,allowed_csi_drivers )
    {
        if(!cJSON_IsObject(allowed_csi_drivers_local_nonprimitive)){
            goto end;
        }
        v1beta1_allowed_csi_driver_t *allowed_csi_driversItem = v1beta1_allowed_csi_driver_parseFromJSON(allowed_csi_drivers_local_nonprimitive);

        list_addElement(allowed_csi_driversList, allowed_csi_driversItem);
    }
    }

    // v1beta1_pod_security_policy_spec->allowed_capabilities
    cJSON *allowed_capabilities = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_security_policy_specJSON, "allowedCapabilities");
    if (allowed_capabilities) { 
    cJSON *allowed_capabilities_local = NULL;
    if(!cJSON_IsArray(allowed_capabilities)) {
        goto end;//primitive container
    }
    allowed_capabilitiesList = list_createList();

    cJSON_ArrayForEach(allowed_capabilities_local, allowed_capabilities)
    {
        if(!cJSON_IsString(allowed_capabilities_local))
        {
            goto end;
        }
        list_addElement(allowed_capabilitiesList , strdup(allowed_capabilities_local->valuestring));
    }
    }

    // v1beta1_pod_security_policy_spec->allowed_flex_volumes
    cJSON *allowed_flex_volumes = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_security_policy_specJSON, "allowedFlexVolumes");
    if (allowed_flex_volumes) { 
    cJSON *allowed_flex_volumes_local_nonprimitive = NULL;
    if(!cJSON_IsArray(allowed_flex_volumes)){
        goto end; //nonprimitive container
    }

    allowed_flex_volumesList = list_createList();

    cJSON_ArrayForEach(allowed_flex_volumes_local_nonprimitive,allowed_flex_volumes )
    {
        if(!cJSON_IsObject(allowed_flex_volumes_local_nonprimitive)){
            goto end;
        }
        v1beta1_allowed_flex_volume_t *allowed_flex_volumesItem = v1beta1_allowed_flex_volume_parseFromJSON(allowed_flex_volumes_local_nonprimitive);

        list_addElement(allowed_flex_volumesList, allowed_flex_volumesItem);
    }
    }

    // v1beta1_pod_security_policy_spec->allowed_host_paths
    cJSON *allowed_host_paths = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_security_policy_specJSON, "allowedHostPaths");
    if (allowed_host_paths) { 
    cJSON *allowed_host_paths_local_nonprimitive = NULL;
    if(!cJSON_IsArray(allowed_host_paths)){
        goto end; //nonprimitive container
    }

    allowed_host_pathsList = list_createList();

    cJSON_ArrayForEach(allowed_host_paths_local_nonprimitive,allowed_host_paths )
    {
        if(!cJSON_IsObject(allowed_host_paths_local_nonprimitive)){
            goto end;
        }
        v1beta1_allowed_host_path_t *allowed_host_pathsItem = v1beta1_allowed_host_path_parseFromJSON(allowed_host_paths_local_nonprimitive);

        list_addElement(allowed_host_pathsList, allowed_host_pathsItem);
    }
    }

    // v1beta1_pod_security_policy_spec->allowed_proc_mount_types
    cJSON *allowed_proc_mount_types = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_security_policy_specJSON, "allowedProcMountTypes");
    if (allowed_proc_mount_types) { 
    cJSON *allowed_proc_mount_types_local = NULL;
    if(!cJSON_IsArray(allowed_proc_mount_types)) {
        goto end;//primitive container
    }
    allowed_proc_mount_typesList = list_createList();

    cJSON_ArrayForEach(allowed_proc_mount_types_local, allowed_proc_mount_types)
    {
        if(!cJSON_IsString(allowed_proc_mount_types_local))
        {
            goto end;
        }
        list_addElement(allowed_proc_mount_typesList , strdup(allowed_proc_mount_types_local->valuestring));
    }
    }

    // v1beta1_pod_security_policy_spec->allowed_unsafe_sysctls
    cJSON *allowed_unsafe_sysctls = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_security_policy_specJSON, "allowedUnsafeSysctls");
    if (allowed_unsafe_sysctls) { 
    cJSON *allowed_unsafe_sysctls_local = NULL;
    if(!cJSON_IsArray(allowed_unsafe_sysctls)) {
        goto end;//primitive container
    }
    allowed_unsafe_sysctlsList = list_createList();

    cJSON_ArrayForEach(allowed_unsafe_sysctls_local, allowed_unsafe_sysctls)
    {
        if(!cJSON_IsString(allowed_unsafe_sysctls_local))
        {
            goto end;
        }
        list_addElement(allowed_unsafe_sysctlsList , strdup(allowed_unsafe_sysctls_local->valuestring));
    }
    }

    // v1beta1_pod_security_policy_spec->default_add_capabilities
    cJSON *default_add_capabilities = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_security_policy_specJSON, "defaultAddCapabilities");
    if (default_add_capabilities) { 
    cJSON *default_add_capabilities_local = NULL;
    if(!cJSON_IsArray(default_add_capabilities)) {
        goto end;//primitive container
    }
    default_add_capabilitiesList = list_createList();

    cJSON_ArrayForEach(default_add_capabilities_local, default_add_capabilities)
    {
        if(!cJSON_IsString(default_add_capabilities_local))
        {
            goto end;
        }
        list_addElement(default_add_capabilitiesList , strdup(default_add_capabilities_local->valuestring));
    }
    }

    // v1beta1_pod_security_policy_spec->default_allow_privilege_escalation
    cJSON *default_allow_privilege_escalation = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_security_policy_specJSON, "defaultAllowPrivilegeEscalation");
    if (default_allow_privilege_escalation) { 
    if(!cJSON_IsBool(default_allow_privilege_escalation))
    {
    goto end; //Bool
    }
    }

    // v1beta1_pod_security_policy_spec->forbidden_sysctls
    cJSON *forbidden_sysctls = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_security_policy_specJSON, "forbiddenSysctls");
    if (forbidden_sysctls) { 
    cJSON *forbidden_sysctls_local = NULL;
    if(!cJSON_IsArray(forbidden_sysctls)) {
        goto end;//primitive container
    }
    forbidden_sysctlsList = list_createList();

    cJSON_ArrayForEach(forbidden_sysctls_local, forbidden_sysctls)
    {
        if(!cJSON_IsString(forbidden_sysctls_local))
        {
            goto end;
        }
        list_addElement(forbidden_sysctlsList , strdup(forbidden_sysctls_local->valuestring));
    }
    }

    // v1beta1_pod_security_policy_spec->fs_group
    cJSON *fs_group = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_security_policy_specJSON, "fsGroup");
    if (!fs_group) {
        goto end;
    }

    
    fs_group_local_nonprim = v1beta1_fs_group_strategy_options_parseFromJSON(fs_group); //nonprimitive

    // v1beta1_pod_security_policy_spec->host_ipc
    cJSON *host_ipc = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_security_policy_specJSON, "hostIPC");
    if (host_ipc) { 
    if(!cJSON_IsBool(host_ipc))
    {
    goto end; //Bool
    }
    }

    // v1beta1_pod_security_policy_spec->host_network
    cJSON *host_network = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_security_policy_specJSON, "hostNetwork");
    if (host_network) { 
    if(!cJSON_IsBool(host_network))
    {
    goto end; //Bool
    }
    }

    // v1beta1_pod_security_policy_spec->host_pid
    cJSON *host_pid = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_security_policy_specJSON, "hostPID");
    if (host_pid) { 
    if(!cJSON_IsBool(host_pid))
    {
    goto end; //Bool
    }
    }

    // v1beta1_pod_security_policy_spec->host_ports
    cJSON *host_ports = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_security_policy_specJSON, "hostPorts");
    if (host_ports) { 
    cJSON *host_ports_local_nonprimitive = NULL;
    if(!cJSON_IsArray(host_ports)){
        goto end; //nonprimitive container
    }

    host_portsList = list_createList();

    cJSON_ArrayForEach(host_ports_local_nonprimitive,host_ports )
    {
        if(!cJSON_IsObject(host_ports_local_nonprimitive)){
            goto end;
        }
        v1beta1_host_port_range_t *host_portsItem = v1beta1_host_port_range_parseFromJSON(host_ports_local_nonprimitive);

        list_addElement(host_portsList, host_portsItem);
    }
    }

    // v1beta1_pod_security_policy_spec->privileged
    cJSON *privileged = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_security_policy_specJSON, "privileged");
    if (privileged) { 
    if(!cJSON_IsBool(privileged))
    {
    goto end; //Bool
    }
    }

    // v1beta1_pod_security_policy_spec->read_only_root_filesystem
    cJSON *read_only_root_filesystem = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_security_policy_specJSON, "readOnlyRootFilesystem");
    if (read_only_root_filesystem) { 
    if(!cJSON_IsBool(read_only_root_filesystem))
    {
    goto end; //Bool
    }
    }

    // v1beta1_pod_security_policy_spec->required_drop_capabilities
    cJSON *required_drop_capabilities = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_security_policy_specJSON, "requiredDropCapabilities");
    if (required_drop_capabilities) { 
    cJSON *required_drop_capabilities_local = NULL;
    if(!cJSON_IsArray(required_drop_capabilities)) {
        goto end;//primitive container
    }
    required_drop_capabilitiesList = list_createList();

    cJSON_ArrayForEach(required_drop_capabilities_local, required_drop_capabilities)
    {
        if(!cJSON_IsString(required_drop_capabilities_local))
        {
            goto end;
        }
        list_addElement(required_drop_capabilitiesList , strdup(required_drop_capabilities_local->valuestring));
    }
    }

    // v1beta1_pod_security_policy_spec->run_as_group
    cJSON *run_as_group = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_security_policy_specJSON, "runAsGroup");
    if (run_as_group) { 
    run_as_group_local_nonprim = v1beta1_run_as_group_strategy_options_parseFromJSON(run_as_group); //nonprimitive
    }

    // v1beta1_pod_security_policy_spec->run_as_user
    cJSON *run_as_user = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_security_policy_specJSON, "runAsUser");
    if (!run_as_user) {
        goto end;
    }

    
    run_as_user_local_nonprim = v1beta1_run_as_user_strategy_options_parseFromJSON(run_as_user); //nonprimitive

    // v1beta1_pod_security_policy_spec->runtime_class
    cJSON *runtime_class = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_security_policy_specJSON, "runtimeClass");
    if (runtime_class) { 
    runtime_class_local_nonprim = v1beta1_runtime_class_strategy_options_parseFromJSON(runtime_class); //nonprimitive
    }

    // v1beta1_pod_security_policy_spec->se_linux
    cJSON *se_linux = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_security_policy_specJSON, "seLinux");
    if (!se_linux) {
        goto end;
    }

    
    se_linux_local_nonprim = v1beta1_se_linux_strategy_options_parseFromJSON(se_linux); //nonprimitive

    // v1beta1_pod_security_policy_spec->supplemental_groups
    cJSON *supplemental_groups = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_security_policy_specJSON, "supplementalGroups");
    if (!supplemental_groups) {
        goto end;
    }

    
    supplemental_groups_local_nonprim = v1beta1_supplemental_groups_strategy_options_parseFromJSON(supplemental_groups); //nonprimitive

    // v1beta1_pod_security_policy_spec->volumes
    cJSON *volumes = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_security_policy_specJSON, "volumes");
    if (volumes) { 
    cJSON *volumes_local = NULL;
    if(!cJSON_IsArray(volumes)) {
        goto end;//primitive container
    }
    volumesList = list_createList();

    cJSON_ArrayForEach(volumes_local, volumes)
    {
        if(!cJSON_IsString(volumes_local))
        {
            goto end;
        }
        list_addElement(volumesList , strdup(volumes_local->valuestring));
    }
    }


    v1beta1_pod_security_policy_spec_local_var = v1beta1_pod_security_policy_spec_create (
        allow_privilege_escalation ? allow_privilege_escalation->valueint : 0,
        allowed_csi_drivers ? allowed_csi_driversList : NULL,
        allowed_capabilities ? allowed_capabilitiesList : NULL,
        allowed_flex_volumes ? allowed_flex_volumesList : NULL,
        allowed_host_paths ? allowed_host_pathsList : NULL,
        allowed_proc_mount_types ? allowed_proc_mount_typesList : NULL,
        allowed_unsafe_sysctls ? allowed_unsafe_sysctlsList : NULL,
        default_add_capabilities ? default_add_capabilitiesList : NULL,
        default_allow_privilege_escalation ? default_allow_privilege_escalation->valueint : 0,
        forbidden_sysctls ? forbidden_sysctlsList : NULL,
        fs_group_local_nonprim,
        host_ipc ? host_ipc->valueint : 0,
        host_network ? host_network->valueint : 0,
        host_pid ? host_pid->valueint : 0,
        host_ports ? host_portsList : NULL,
        privileged ? privileged->valueint : 0,
        read_only_root_filesystem ? read_only_root_filesystem->valueint : 0,
        required_drop_capabilities ? required_drop_capabilitiesList : NULL,
        run_as_group ? run_as_group_local_nonprim : NULL,
        run_as_user_local_nonprim,
        runtime_class ? runtime_class_local_nonprim : NULL,
        se_linux_local_nonprim,
        supplemental_groups_local_nonprim,
        volumes ? volumesList : NULL
        );

    return v1beta1_pod_security_policy_spec_local_var;
end:
    if (allowed_csi_driversList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, allowed_csi_driversList) {
            v1beta1_allowed_csi_driver_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(allowed_csi_driversList);
        allowed_csi_driversList = NULL;
    }
    if (allowed_capabilitiesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, allowed_capabilitiesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(allowed_capabilitiesList);
        allowed_capabilitiesList = NULL;
    }
    if (allowed_flex_volumesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, allowed_flex_volumesList) {
            v1beta1_allowed_flex_volume_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(allowed_flex_volumesList);
        allowed_flex_volumesList = NULL;
    }
    if (allowed_host_pathsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, allowed_host_pathsList) {
            v1beta1_allowed_host_path_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(allowed_host_pathsList);
        allowed_host_pathsList = NULL;
    }
    if (allowed_proc_mount_typesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, allowed_proc_mount_typesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(allowed_proc_mount_typesList);
        allowed_proc_mount_typesList = NULL;
    }
    if (allowed_unsafe_sysctlsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, allowed_unsafe_sysctlsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(allowed_unsafe_sysctlsList);
        allowed_unsafe_sysctlsList = NULL;
    }
    if (default_add_capabilitiesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, default_add_capabilitiesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(default_add_capabilitiesList);
        default_add_capabilitiesList = NULL;
    }
    if (forbidden_sysctlsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, forbidden_sysctlsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(forbidden_sysctlsList);
        forbidden_sysctlsList = NULL;
    }
    if (fs_group_local_nonprim) {
        v1beta1_fs_group_strategy_options_free(fs_group_local_nonprim);
        fs_group_local_nonprim = NULL;
    }
    if (host_portsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, host_portsList) {
            v1beta1_host_port_range_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(host_portsList);
        host_portsList = NULL;
    }
    if (required_drop_capabilitiesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, required_drop_capabilitiesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(required_drop_capabilitiesList);
        required_drop_capabilitiesList = NULL;
    }
    if (run_as_group_local_nonprim) {
        v1beta1_run_as_group_strategy_options_free(run_as_group_local_nonprim);
        run_as_group_local_nonprim = NULL;
    }
    if (run_as_user_local_nonprim) {
        v1beta1_run_as_user_strategy_options_free(run_as_user_local_nonprim);
        run_as_user_local_nonprim = NULL;
    }
    if (runtime_class_local_nonprim) {
        v1beta1_runtime_class_strategy_options_free(runtime_class_local_nonprim);
        runtime_class_local_nonprim = NULL;
    }
    if (se_linux_local_nonprim) {
        v1beta1_se_linux_strategy_options_free(se_linux_local_nonprim);
        se_linux_local_nonprim = NULL;
    }
    if (supplemental_groups_local_nonprim) {
        v1beta1_supplemental_groups_strategy_options_free(supplemental_groups_local_nonprim);
        supplemental_groups_local_nonprim = NULL;
    }
    if (volumesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, volumesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(volumesList);
        volumesList = NULL;
    }
    return NULL;

}
