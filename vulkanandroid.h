#pragma once

#ifndef VULKANANDROID_H
#define VULKANANDROID_H

// Vulkan needs to be loaded dynamically on android

#pragma once

#ifndef VULKANANDROID_HPP
#define VULKANANDROID_HPP

#include "vulkan/vulkan.h"
#include <sstream>

#ifdef ANDROID

// Function pointer prototypes
// Not complete, just the functions used in the caps viewer!
extern PFN_vkCreateInstance vkCreateInstance;
extern PFN_vkCreateDevice vkCreateDevice;
extern PFN_vkEnumeratePhysicalDevices vkEnumeratePhysicalDevices;
extern PFN_vkGetPhysicalDeviceProperties vkGetPhysicalDeviceProperties;
extern PFN_vkEnumerateDeviceExtensionProperties vkEnumerateDeviceExtensionProperties;
extern PFN_vkEnumerateDeviceLayerProperties vkEnumerateDeviceLayerProperties;
extern PFN_vkGetPhysicalDeviceFormatProperties vkGetPhysicalDeviceFormatProperties;
extern PFN_vkGetPhysicalDeviceFeatures vkGetPhysicalDeviceFeatures;
extern PFN_vkGetPhysicalDeviceQueueFamilyProperties vkGetPhysicalDeviceQueueFamilyProperties;
extern PFN_vkGetPhysicalDeviceMemoryProperties vkGetPhysicalDeviceMemoryProperties;
extern PFN_vkEnumerateInstanceExtensionProperties vkEnumerateInstanceExtensionProperties;
extern PFN_vkEnumerateInstanceLayerProperties vkEnumerateInstanceLayerProperties;
extern PFN_vkGetPhysicalDeviceMemoryProperties vkGetPhysicalDeviceMemoryProperties;

bool loadVulkanLibrary();
void loadVulkanFunctions(VkInstance instance);

namespace std
{
    // to_tring is missing from std in recent NDK versions...q
    template <typename T>
    std::string to_string(T value)
    {
        std::ostringstream os;
        os << value;
        return os.str();
    }
}

#endif

#endif // VULKANANDROID_HPP


#endif // VULKANANDROID_H
