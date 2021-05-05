
#include <stdio.h>
#include <stdlib.h>
#include <CL/cl.h>



// step1 
cl_int clGetPlatformIDs(cl_uint num_entries,cl_platform_id *platforms,cl_uint *num_platforms);


cl_uint num_platforms = 0;
cl_platform_id *platforms = NULL;

// To get number of platforms
cl_int status= clGetPlatformIDs(0, NULL, &num_platforms);
// Allocate enough space for each platform
platforms=(cl_platform_id*) malloc(num_platforms*sizeof(cl_platform_id));
// To fill in Platforms info.
status=clGetPlatformIDs(num_platforms, platforms, NULL);


// step2
cl_int clGetDeviceIDs(cl_platform_id platform,cl_device_type device_type,cl_uint num_entries,cl_device_id *devices,cl_uint *num_devices);

// step3
cl_context clCreateContext(const cl_context_properties *properties,cl_uint num_devices,const cl_device_id *devices,void(CL_CALLBACK *pfn_notify)(const char *errinfo,const void *private_info,size_t cb,void *user_data),void *user_data,cl_int *errcode_ret);

// step4
cl_command_queue clCreateCommandQueue(cl_context context,cl_device_id device,cl_command_queue_properties properties,cl_int *errcode_ret);

// step5
cl_mem clCreateBuffer(cl_context context,cl_mem_flags flags,size_t size,void *host_ptr,cl_int *errcode_ret);

// step6
cl_int clEnqueueWriteBuffer(cl_command_queue command_queue,cl_mem buffer,cl_bool blocking_write,size_t offset,size_t cb,const void *ptr,cl_uint num_events_in_wait_list,const cl_event *event_wait_list,cl_event *event);

// step7
cl_program clCreateProgramWithSource(cl_context context,cl_uint count,const char **strings,const size_t *lengths,cl_int *errcode_ret);

// step8
cl_kernel clCreateKernel(cl_program program,const char *kernel_name,cl_int *errcode_ret);

// step9
cl_int clSetKernelArg(cl_kernel kernel,cl_uint arg_index,size_t arg_size,const void *arg_value);

// step10
// Define an index space (global work size) of work items forexecution. 
// A workgroup size (local work size) is not required, but canbe used.
size_t globalWorkSize[1];
// There are ’elements(1024)’ work-items
globalWorkSize[0] = elements;


// step11
cl_int clEnqueueNDRangeKernel(cl_command_queue command_queue,cl_kernel kernel,cl_uint work_dim,const size_t *global_work_offset,const size_t *global_work_size,const size_t *local_work_size,cl_uint num_events_in_wait_list,const cl_event *event_wait_list,cl_event *event);

// step12
cl_int clEnqueueReadBuffer(cl_command_queue command_queue,cl_mem buffer,cl_bool blocking_write,size_t offset,size_t cb,const void *ptr,cl_uint num_events_in_wait_list,const cl_event *event_wait_list,cl_event *event);


// step13
// Free OpenCL resourcesclReleaseKernel(kernel);
clReleaseProgram(program);
clReleaseCommandQueue(cmdQueue);
clReleaseMemObject(bufferA);
clReleaseMemObject(bufferB);
clReleaseMemObject(bufferC);
clReleaseContext(context);
// Free host resourcesfree(A);
free(B);
free(C);
free(platforms);
free(devices);

