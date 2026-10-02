LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := cheatmenu
LOCAL_LDLIBS := -llog -lGLESv3 -lEGL -landroid

LOCAL_SRC_FILES := $(wildcard $(LOCAL_PATH)/*.cpp) \
                   $(wildcard $(LOCAL_PATH)/game/*.cpp) \
				   $(wildcard $(LOCAL_PATH)/gui/*.cpp) \
                   $(wildcard $(LOCAL_PATH)/util/*.cpp) \
				   $(wildcard $(LOCAL_PATH)/vendor/imgui/*.cpp) \

LOCAL_CPPFLAGS := -D_ARM_ \
				  -w \
				  -pthread \
				  -fpack-struct=1 \
				  -Wall \
				  -fdiagnostics-color=auto \
				  -O3 \
				  -ffast-math \
				  -funroll-loops \
				  -fomit-frame-pointer \
				  -fno-ident \
				  -fno-asynchronous-unwind-tables \
				  -fvisibility=hidden \
				  -fvisibility-inlines-hidden \
				  -fno-exceptions \
				  -fno-rtti \
				  -fstack-protector-strong \
				  -fstrict-aliasing \
				  -fpie \
				  -fpic \
				  -fno-common \
				  -fmerge-all-constants \
				  -fno-inline-functions-called-once \
				  -fdelete-null-pointer-checks \
				  -funit-at-a-time \
				  -fno-builtin \
				  -fno-threadsafe-statics \
				  -fno-function-sections \
				  -fno-data-sections \
				  -fno-sanitize=undefined,address \
				  -fno-short-enums \
				  -fno-math-errno

LOCAL_LDFLAGS := -Wl,-z,now \
				 -Wl,-z,relro \
				 -Wl,-z,noexecstack \
				 -Wl,-s \
				 -Wl,--build-id=none \
				 -Wl,--strip-debug \
				 -Wl,--exclude-libs,ALL
 
LOCAL_STATIC_LIBRARIES := dobby_prebuilt

include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)

LOCAL_MODULE := dobby_prebuilt
LOCAL_SRC_FILES := vendor/Dobby/$(TARGET_ARCH_ABI)/libdobby.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/vendor/Dobby

include $(PREBUILT_STATIC_LIBRARY)