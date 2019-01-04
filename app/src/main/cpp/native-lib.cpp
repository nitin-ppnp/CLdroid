#include <jni.h>
#include <string>
#include <boost/compute/core.hpp>
#include <iostream>

using namespace std;
namespace compute = boost::compute;

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_nsaini_cldroid_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {

    std::stringstream strout;
    strout << "Hello World. This is OpenCL" << endl;

    strout << "Total CL compatible devices are : " << compute::system::device_count() << endl;

    std::vector<compute::device>  devices = compute::system::devices();

    std::vector<compute::device>::iterator it;
    int i;
    for(it = devices.begin(), i=0;it != devices.end(); ++it,++i)
    {
        strout << "device " << i << " : " << it->name() << endl;
    }


    std::string hello = strout.str() + "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
