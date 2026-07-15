#pragma once
#include <string>
#include <vector>
#include "SampleItem.h"

class SampleRepository
{
public:
    SampleItem& Add(const std::string& name, double avgProcessMinutes, double yieldRate);
    const std::vector<SampleItem>& GetAll() const;
    SampleItem* FindById(const std::string& id);
    std::vector<SampleItem*> FindByNameKeyword(const std::string& keyword);

private:
    std::vector<SampleItem> samples;
    int nextId = 1;
};
