find_package(OpenCV REQUIRED)
find_package(Boost REQUIRED COMPONENTS system thread)
add_executable(CV_Auric main.cpp Target.cpp TargetDetector.cpp TargetProcessor.cpp NetworkController.cpp VideoDevice.cpp GUIManager.cpp CmdLineInterface.cpp AppConfig.cpp)
target_link_libraries(CV_Auric ${OpenCV_LIBS} ${Boost_LIBRARIES})
