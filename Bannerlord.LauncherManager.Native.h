
#ifndef SRC_BINDINGS_H_
#define SRC_BINDINGS_H_

#ifndef __cplusplus

#include <stdlib.h>
#include <stdint.h>

#else

#include <memory>
#include <string>
#include <cstdint>
#include <cuchar>

namespace Bannerlord::LauncherManager::Native
{
    extern "C"
    {
#endif

#ifndef __cplusplus
        typedef char16_t wchar_t;
#endif
        typedef char16_t param_string;
        typedef char16_t param_json;
        typedef uint8_t param_data;
        typedef uint8_t param_bool;
        typedef int32_t param_int;
        typedef uint32_t param_uint;
        typedef void param_ptr;
        typedef struct param_callback
        {
            void *p_callback_ptr;
            void(__cdecl *p_callback)(param_ptr *, param_ptr *);
        } param_callback;

        typedef struct return_value_void
        {
            param_string *const error;
        } return_value_void;
        typedef struct return_value_string
        {
            param_string *const error;
            param_string *const value;
        } return_value_string;
        typedef struct return_value_json
        {
            param_string *const error;
            param_json *const value;
        } return_value_json;
        typedef struct return_value_data
        {
            param_string *const error;
            param_data *const value;
            param_int length;
        } return_value_data;
        typedef struct return_value_bool
        {
            param_string *const error;
            param_bool const value;
        } return_value_bool;
        typedef struct return_value_int32
        {
            param_string *const error;
            param_int const value;
        } return_value_int32;
        typedef struct return_value_uint32
        {
            param_string *const error;
            param_uint const value;
        } return_value_uint32;
        typedef struct return_value_ptr
        {
            param_string *const error;
            param_ptr *const value;
        } return_value_ptr;

    return_value_uint32* __cdecl bfv_get_change_set(param_string* p_game_folder_path, param_string* p_lib_assembly);
    return_value_string* __cdecl bfv_get_version(param_string* p_game_folder_path, param_string* p_lib_assembly);
    return_value_uint32* __cdecl bfv_get_version_type(param_string* p_game_folder_path, param_string* p_lib_assembly);
    return_value_bool* __cdecl bmm_are_all_dependencies_of_module_present(param_json* p_source, param_json* p_module);
    return_value_int32* __cdecl bmm_compare_versions(param_json* p_x, param_json* p_y);
    return_value_void* __cdecl bmm_disable_module(param_ptr* p_owner, param_json* p_module, param_json* p_target_module, return_value_bool* (__cdecl p_get_selected)(param_ptr*, param_string*) , return_value_void* (__cdecl p_set_selected)(param_ptr*, param_string*, param_bool) , return_value_bool* (__cdecl p_get_disabled)(param_ptr*, param_string*) , return_value_void* (__cdecl p_set_disabled)(param_ptr*, param_string*, param_bool) );
    return_value_void* __cdecl bmm_enable_module(param_ptr* p_owner, param_json* p_module, param_json* p_target_module, return_value_bool* (__cdecl p_get_selected)(param_ptr*, param_string*) , return_value_void* (__cdecl p_set_selected)(param_ptr*, param_string*, param_bool) , return_value_bool* (__cdecl p_get_disabled)(param_ptr*, param_string*) , return_value_void* (__cdecl p_set_disabled)(param_ptr*, param_string*, param_bool) );
    return_value_json* __cdecl bmm_get_dependencies_all(param_json* p_module);
    return_value_json* __cdecl bmm_get_dependencies_incompatibles(param_json* p_module);
    return_value_json* __cdecl bmm_get_dependencies_load_after_this(param_json* p_module);
    return_value_json* __cdecl bmm_get_dependencies_load_before_this(param_json* p_module);
    return_value_json* __cdecl bmm_get_dependent_modules_of(param_json* p_source, param_json* p_module);
    return_value_json* __cdecl bmm_get_dependent_modules_of_with_options(param_json* p_source, param_json* p_module, param_json* p_options);
    return_value_json* __cdecl bmm_get_module_info(param_string* p_xml_content);
    return_value_json* __cdecl bmm_get_module_info_with_path(param_string* p_xml_content, param_string* p_path);
    return_value_json* __cdecl bmm_get_sub_module_info(param_string* p_xml_content);
    return_value_json* __cdecl bmm_sort(param_json* p_source);
    return_value_json* __cdecl bmm_sort_with_options(param_json* p_source, param_json* p_options);
    return_value_json* __cdecl bmm_validate_load_order(param_json* p_modules, param_json* p_target_module);
    return_value_json* __cdecl bmm_validate_module(param_ptr* p_owner, param_json* p_modules, param_json* p_target_module, return_value_bool* (__cdecl p_is_selected)(param_ptr*, param_string*) );
    void* __cdecl common_alloc(size_t size);
    int32_t __cdecl common_alloc_alive_count();
    void __cdecl common_dealloc(param_ptr* ptr);
    return_value_string* __cdecl utils_get_dependency_hint(param_json* p_module);
    return_value_json* __cdecl utils_is_load_order_correct(param_json* p_modules);
    return_value_string* __cdecl utils_translate(param_string* p_text);
    return_value_void* __cdecl ve_check_for_root_harmony(param_ptr* p_handle);
    return_value_ptr* __cdecl ve_create_handler(param_ptr* p_owner);
    return_value_void* __cdecl ve_dialog_test_file_open(param_ptr* p_handle, param_ptr* p_callback_handler, void (__cdecl p_callback)(param_ptr*, param_string*) );
    return_value_void* __cdecl ve_dialog_test_warning(param_ptr* p_handle, param_ptr* p_callback_handler, void (__cdecl p_callback)(param_ptr*, param_string*) );
    return_value_void* __cdecl ve_dispose_handler(param_ptr* p_handle);
    return_value_string* __cdecl ve_get_game_version(param_ptr* p_handle);
    return_value_json* __cdecl ve_get_modules(param_ptr* p_handle);
    return_value_string* __cdecl ve_get_save_file_path(param_ptr* p_handle, param_string* p_save_file);
    return_value_json* __cdecl ve_get_save_files(param_ptr* p_handle);
    return_value_json* __cdecl ve_get_save_metadata(param_ptr* p_handle, param_string* p_save_file, param_data* p_data, param_int data_len);
    return_value_json* __cdecl ve_install_module(param_ptr* p_handle, param_json* p_files, param_string* p_destination_path);
    return_value_bool* __cdecl ve_is_sorting(param_ptr* p_handle);
    return_value_void* __cdecl ve_load_localization(param_ptr* p_handle, param_string* p_xml);
    return_value_void* __cdecl ve_module_list_handler_export(param_ptr* p_handle);
    return_value_void* __cdecl ve_module_list_handler_export_save_file(param_ptr* p_handle, param_string* p_save_file);
    return_value_void* __cdecl ve_module_list_handler_import(param_ptr* p_handle, param_ptr* p_callback_handler, void (__cdecl p_callback)(param_ptr*, param_bool) );
    return_value_void* __cdecl ve_module_list_handler_import_save_file(param_ptr* p_handle, param_string* p_save_file, param_ptr* p_callback_handler, void (__cdecl p_callback)(param_ptr*, param_bool) );
    return_value_json* __cdecl ve_order_by_load_order(param_ptr* p_handle, param_json* p_load_order);
    return_value_void* __cdecl ve_refresh_game_parameters(param_ptr* p_handle);
    return_value_void* __cdecl ve_refresh_modules(param_ptr* p_handle);
    return_value_void* __cdecl ve_register_callbacks(param_ptr* p_handle, return_value_void* (__cdecl p_set_game_parameters)(param_ptr*, param_string*, param_json*) , return_value_json* (__cdecl p_load_load_order)(param_ptr*) , return_value_void* (__cdecl p_save_load_order)(param_ptr*, param_json*) , return_value_void* (__cdecl p_send_notification)(param_ptr*, param_string*, param_string*, param_string*, param_uint) , return_value_void* (__cdecl p_send_dialog)(param_ptr*, param_string*, param_string*, param_string*, param_json*, param_ptr*, void (__cdecl )(param_ptr*, param_string*)) , return_value_string* (__cdecl p_get_install_path)(param_ptr*) , return_value_data* (__cdecl p_read_file_content)(param_ptr*, param_string*, param_int, param_int) , return_value_void* (__cdecl p_write_file_content)(param_ptr*, param_string*, param_data*, param_int) , return_value_json* (__cdecl p_read_directory_file_list)(param_ptr*, param_string*) , return_value_json* (__cdecl p_read_directory_list)(param_ptr*, param_string*) , return_value_json* (__cdecl p_get_module_view_models)(param_ptr*) , return_value_void* (__cdecl p_set_module_view_models)(param_ptr*, param_json*) , return_value_json* (__cdecl p_get_options)(param_ptr*) , return_value_json* (__cdecl p_get_state)(param_ptr*) );
    return_value_void* __cdecl ve_set_game_parameter_executable(param_ptr* p_handle, param_string* p_executable);
    return_value_void* __cdecl ve_set_game_parameter_save_file(param_ptr* p_handle, param_string* p_save_file);
    return_value_void* __cdecl ve_sort(param_ptr* p_handle);
    return_value_bool* __cdecl ve_sort_helper_change_module_position(param_ptr* p_handle, param_json* p_module_view_model, param_int insertIndex);
    return_value_json* __cdecl ve_sort_helper_toggle_module_selection(param_ptr* p_handle, param_json* p_module_view_model);
    return_value_json* __cdecl ve_sort_helper_validate_module(param_ptr* p_handle, param_json* p_module_view_model);
    return_value_json* __cdecl ve_test_module(param_ptr* p_handle, param_json* p_files);


#ifdef __cplusplus
    }
}
#endif

#endif
