scp -r ../build-pepper/sdk/bin/pepper_localizer nao@$PEPPER_IP:spqrel_launch/bin
scp -r ../build-pepper/sdk/bin/pepper_planner   nao@$PEPPER_IP:spqrel_launch/bin
scp -r ../build-pepper/sdk/lib/libnaoqi_localizer_library.so    nao@$PEPPER_IP:spqrel_launch/lib
scp -r ../build-pepper/sdk/lib/libnaoqi_planner_library.so      nao@$PEPPER_IP:spqrel_launch/lib
scp -r ../build-pepper/sdk/lib/libnaoqi_sensor_utils_library.so nao@$PEPPER_IP:spqrel_launch/lib
scp -r ../build-pepper/sdk/lib/libsrrg_localizer2d_library.so   nao@$PEPPER_IP:spqrel_launch/lib
scp -r ../build-pepper/sdk/lib/libsrrg_path_map_library.so      nao@$PEPPER_IP:spqrel_launch/lib
scp -r ../build-pepper/sdk/lib/libsrrg_planner2d_library.so     nao@$PEPPER_IP:spqrel_launch/lib
scp -r ../build-pepper/sdk/lib/libsrrg_system_utils_yaml.so     nao@$PEPPER_IP:spqrel_launch/lib
