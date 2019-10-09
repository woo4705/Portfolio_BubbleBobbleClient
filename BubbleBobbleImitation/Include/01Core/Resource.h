#pragma once
#include <unordered_map>
#include <windows.h>
using namespace std;

class Resource
{
public:
	Resource();
	~Resource();
	
	static Resource* GetInst() {
		if (resource_Inst == NULL)
			resource_Inst = new Resource();
		return resource_Inst;
	}
	
	LPCWSTR GetRoute(string key);
	HBITMAP GetResourceById(string key);

	void ClearLoadedResource(string key);
	void RestoreLoadedResource(string key, HBITMAP bitmap);
private:
	void InitResourceRouteData();
	void InitLoadedResource();

	static Resource* resource_Inst;
	static unordered_map<string, LPCWSTR> resource_route_info;
	static unordered_map<string, HBITMAP> loaded_resource;

};

