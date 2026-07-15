#include "SampleRepository.h"
#include <sstream>
#include <iomanip>
#include <algorithm>

SampleItem& SampleRepository::Add(const std::string& name, double avgProcessMinutes, double yieldRate)
{
    std::ostringstream oss;
    oss << "S-" << std::setw(3) << std::setfill('0') << nextId++;

    samples.emplace_back(oss.str(), name, avgProcessMinutes, yieldRate, 0);
    return samples.back();
}

const std::vector<SampleItem>& SampleRepository::GetAll() const
{
    return samples;
}

SampleItem* SampleRepository::FindById(const std::string& id)
{
    for (SampleItem& sample : samples)
    {
        if (sample.GetId() == id)
        {
            return &sample;
        }
    }
    return nullptr;
}

std::vector<SampleItem*> SampleRepository::FindByNameKeyword(const std::string& keyword)
{
    std::vector<SampleItem*> result;
    for (SampleItem& sample : samples)
    {
        if (sample.GetName().find(keyword) != std::string::npos)
        {
            result.push_back(&sample);
        }
    }
    return result;
}
