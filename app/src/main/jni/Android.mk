LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := MyModMenu
LOCAL_SRC_FILES := Main.cpp \
                   imgui/imgui.cpp \
                   imgui/imgui_demo.cpp \
                   imgui/imgui_draw.cpp \
                   imgui/imgui_widgets.cpp \
                   imgui/imgui_tables.cpp

# Жорстко вказуємо компілятору, де шукати заголовочні файли imgui
LOCAL_C_INCLUDES := $(LOCAL_PATH) \
                    $(LOCAL_PATH)/imgui

LOCAL_CFLAGS := -I$(LOCAL_PATH) -I$(LOCAL_PATH)/imgui

LOCAL_LDLIBS := -llog -landroid

include $(BUILD_SHARED_LIBRARY)
