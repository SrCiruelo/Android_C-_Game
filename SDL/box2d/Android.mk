#Al parecer ndk-build y cmake se pueden usar juntos pero causaría problemas

#No he podido encontrar una función parecida include_directories
#De forma que las rutas del tipo "box2d/b2_setting.h" no funcionan

#En los archivos cpp con crear un link símbolico a la carpeta include en collision,dynamics..
#y cambiar alguna ruta en que usa la forma box2d/ innecesariamente funcionaría

#hay algunas cabeceras que no funcionan muy bien por el hecho de que
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

SRC_FILE_PATH := $(LOCAL_PATH)/src
LOCAL_MODULE := box2d

LOCAL_C_INCLUDES := $(LOCAL_PATH)/include/box2d-all

#FILE_LIST := $(wildcard $(SRC_FILE_PATH)/*.cpp)
LOCAL_SRC_FILES :=  $(SRC_FILE_PATH)/collision/b2_broad_phase.cpp \
					$(SRC_FILE_PATH)/collision/b2_chain_shape.cpp \
					$(SRC_FILE_PATH)/collision/b2_circle_shape.cpp \
					$(SRC_FILE_PATH)/collision/b2_collide_circle.cpp \
					$(SRC_FILE_PATH)/collision/b2_collide_edge.cpp \
					$(SRC_FILE_PATH)/collision/b2_collide_polygon.cpp \
					$(SRC_FILE_PATH)/collision/b2_collision.cpp \
					$(SRC_FILE_PATH)/collision/b2_distance.cpp \
					$(SRC_FILE_PATH)/collision/b2_dynamic_tree.cpp \
					$(SRC_FILE_PATH)/collision/b2_edge_shape.cpp \
					$(SRC_FILE_PATH)/collision/b2_polygon_shape.cpp \
					$(SRC_FILE_PATH)/collision/b2_time_of_impact.cpp \
					$(SRC_FILE_PATH)/common/b2_block_allocator.cpp \
					$(SRC_FILE_PATH)/common/b2_draw.cpp \
					$(SRC_FILE_PATH)/common/b2_math.cpp \
					$(SRC_FILE_PATH)/common/b2_settings.cpp \
					$(SRC_FILE_PATH)/common/b2_stack_allocator.cpp \
					$(SRC_FILE_PATH)/common/b2_timer.cpp \
					$(SRC_FILE_PATH)/dynamics/b2_body.cpp \
					$(SRC_FILE_PATH)/dynamics/b2_chain_circle_contact.cpp \
					$(SRC_FILE_PATH)/dynamics/b2_chain_polygon_contact.cpp \
					$(SRC_FILE_PATH)/dynamics/b2_circle_contact.cpp \
					$(SRC_FILE_PATH)/dynamics/b2_contact.cpp \
					$(SRC_FILE_PATH)/dynamics/b2_contact_manager.cpp \
					$(SRC_FILE_PATH)/dynamics/b2_contact_solver.cpp \
					$(SRC_FILE_PATH)/dynamics/b2_distance_joint.cpp \
					$(SRC_FILE_PATH)/dynamics/b2_edge_circle_contact.cpp \
					$(SRC_FILE_PATH)/dynamics/b2_edge_polygon_contact.cpp \
					$(SRC_FILE_PATH)/dynamics/b2_fixture.cpp \
					$(SRC_FILE_PATH)/dynamics/b2_friction_joint.cpp \
					$(SRC_FILE_PATH)/dynamics/b2_gear_joint.cpp \
					$(SRC_FILE_PATH)/dynamics/b2_island.cpp \
					$(SRC_FILE_PATH)/dynamics/b2_joint.cpp \
					$(SRC_FILE_PATH)/dynamics/b2_motor_joint.cpp \
					$(SRC_FILE_PATH)/dynamics/b2_mouse_joint.cpp \
					$(SRC_FILE_PATH)/dynamics/b2_polygon_circle_contact.cpp \
					$(SRC_FILE_PATH)/dynamics/b2_polygon_contact.cpp \
					$(SRC_FILE_PATH)/dynamics/b2_prismatic_joint.cpp \
					$(SRC_FILE_PATH)/dynamics/b2_pulley_joint.cpp \
					$(SRC_FILE_PATH)/dynamics/b2_revolute_joint.cpp \
					$(SRC_FILE_PATH)/dynamics/b2_rope_joint.cpp \
					$(SRC_FILE_PATH)/dynamics/b2_weld_joint.cpp \
					$(SRC_FILE_PATH)/dynamics/b2_wheel_joint.cpp \
					$(SRC_FILE_PATH)/dynamics/b2_world.cpp \
					$(SRC_FILE_PATH)/dynamics/b2_world_callbacks.cpp \
					$(SRC_FILE_PATH)/rope/b2_rope.cpp


include $(BUILD_SHARED_LIBRARY)
