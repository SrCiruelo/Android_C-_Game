LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := main

SDL_PATH := ../SDL
SDL_IMAGE_PATH := ../SDL_IMAGE
FILES_PATH := -FILES_PATH="../../Files"

LOCAL_CPPFLAGS += -std=c++11

LOCAL_C_INCLUDES := $(LOCAL_PATH)/$(SDL_PATH)/include \
					$(LOCAL_PATH)/$(SDL_IMAGE_PATH)


# Add your application source files here...
LOCAL_SRC_FILES := main.cpp \
				 Game_Logic/Game.cpp \
				 Rendering/SpriteSheet_Animation.cpp \
				 Rendering/Sprite.cpp \
				 Rendering/Scrolling_Texture.cpp \
				 Game_Logic/Game_Initializations.cpp \
				 Rendering/Game_Renderer.cpp \
				 Physics/My_B2_World.cpp \
				 Physics/PhysicsObject.cpp \
				 Physics/Dynamic_Physic_Object.cpp \
				 Physics/Dynamic_Trigger.cpp \
				 Physics/Collision_Handler.cpp \
				 Game_Logic/Character_Controller.cpp \
				 Game_Logic/Event_Handler.cpp \
				 Physics/Static_Physic_Object.cpp \
				 Game_Logic/Obstacle_Controller.cpp \
				 Game_Logic/Animation_Handler.cpp \
				 Game_Logic/Obstacle_Handler.cpp \

LOCAL_SHARED_LIBRARIES := SDL2
LOCAL_SHARED_LIBRARIES += SDL2_image
LOCAL_SHARED_LIBRARIES += box2d

LOCAL_LDLIBS := -lGLESv1_CM -lGLESv2 -llog

include $(BUILD_SHARED_LIBRARY)
