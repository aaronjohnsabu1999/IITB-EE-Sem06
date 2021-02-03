/* clang-format off */
/*
 * Generated file - do not edit.
 * Command: /mongoose-os/tools/mgos_gen_config.py --c_name=mgos_ro_vars --c_global_name=mgos_sys_ro_vars --dest_dir=/data/fwbuild-volumes/2.17.0/apps/Timers/esp32/build_contexts/build_ctx_678271692/build/gen/ /mongoose-os/src/mgos_ro_vars_schema.yaml
 */

#include "mgos_ro_vars.h"

#include <stddef.h>

#include "mgos_config_util.h"

const struct mgos_conf_entry mgos_ro_vars_schema_[7] = {
  {.type = CONF_TYPE_OBJECT, .key = "", .offset = 0, .num_desc = 6},
  {.type = CONF_TYPE_STRING, .key = "mac_address", .offset = offsetof(struct mgos_ro_vars, mac_address)},
  {.type = CONF_TYPE_STRING, .key = "arch", .offset = offsetof(struct mgos_ro_vars, arch)},
  {.type = CONF_TYPE_STRING, .key = "app", .offset = offsetof(struct mgos_ro_vars, app)},
  {.type = CONF_TYPE_STRING, .key = "fw_version", .offset = offsetof(struct mgos_ro_vars, fw_version)},
  {.type = CONF_TYPE_STRING, .key = "fw_timestamp", .offset = offsetof(struct mgos_ro_vars, fw_timestamp)},
  {.type = CONF_TYPE_STRING, .key = "fw_id", .offset = offsetof(struct mgos_ro_vars, fw_id)},
};

const struct mgos_conf_entry *mgos_ro_vars_schema() {
  return mgos_ro_vars_schema_;
}

/* Global instance */
struct mgos_ro_vars mgos_sys_ro_vars;
const struct mgos_ro_vars mgos_ro_vars_defaults = {
  .mac_address = NULL,
  .arch = NULL,
  .app = NULL,
  .fw_version = NULL,
  .fw_timestamp = NULL,
  .fw_id = NULL,
};

/* mac_address */
#define MGOS_RO_VARS_HAVE_MAC_ADDRESS
#define MGOS_SYS_RO_VARS_HAVE_MAC_ADDRESS
const char * mgos_ro_vars_get_mac_address(struct mgos_ro_vars *cfg) {
  return cfg->mac_address;
}
void mgos_ro_vars_set_mac_address(struct mgos_ro_vars *cfg, const char * v) {
  mgos_conf_set_str(&cfg->mac_address, v);
}

/* arch */
#define MGOS_RO_VARS_HAVE_ARCH
#define MGOS_SYS_RO_VARS_HAVE_ARCH
const char * mgos_ro_vars_get_arch(struct mgos_ro_vars *cfg) {
  return cfg->arch;
}
void mgos_ro_vars_set_arch(struct mgos_ro_vars *cfg, const char * v) {
  mgos_conf_set_str(&cfg->arch, v);
}

/* app */
#define MGOS_RO_VARS_HAVE_APP
#define MGOS_SYS_RO_VARS_HAVE_APP
const char * mgos_ro_vars_get_app(struct mgos_ro_vars *cfg) {
  return cfg->app;
}
void mgos_ro_vars_set_app(struct mgos_ro_vars *cfg, const char * v) {
  mgos_conf_set_str(&cfg->app, v);
}

/* fw_version */
#define MGOS_RO_VARS_HAVE_FW_VERSION
#define MGOS_SYS_RO_VARS_HAVE_FW_VERSION
const char * mgos_ro_vars_get_fw_version(struct mgos_ro_vars *cfg) {
  return cfg->fw_version;
}
void mgos_ro_vars_set_fw_version(struct mgos_ro_vars *cfg, const char * v) {
  mgos_conf_set_str(&cfg->fw_version, v);
}

/* fw_timestamp */
#define MGOS_RO_VARS_HAVE_FW_TIMESTAMP
#define MGOS_SYS_RO_VARS_HAVE_FW_TIMESTAMP
const char * mgos_ro_vars_get_fw_timestamp(struct mgos_ro_vars *cfg) {
  return cfg->fw_timestamp;
}
void mgos_ro_vars_set_fw_timestamp(struct mgos_ro_vars *cfg, const char * v) {
  mgos_conf_set_str(&cfg->fw_timestamp, v);
}

/* fw_id */
#define MGOS_RO_VARS_HAVE_FW_ID
#define MGOS_SYS_RO_VARS_HAVE_FW_ID
const char * mgos_ro_vars_get_fw_id(struct mgos_ro_vars *cfg) {
  return cfg->fw_id;
}
void mgos_ro_vars_set_fw_id(struct mgos_ro_vars *cfg, const char * v) {
  mgos_conf_set_str(&cfg->fw_id, v);
}
bool mgos_sys_ro_vars_get(const struct mg_str key, struct mg_str *value) {
  return mgos_config_get(key, value, &mgos_sys_ro_vars, mgos_ro_vars_schema());
}
bool mgos_sys_ro_vars_set(const struct mg_str key, const struct mg_str value, bool free_strings) {
  return mgos_config_set(key, value, &mgos_sys_ro_vars, mgos_ro_vars_schema(), free_strings);
}
