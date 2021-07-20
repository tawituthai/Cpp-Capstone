#include <io2d.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <optional>

#include "render.h"
#include "route_model.h"

// May of may-not return output
static std::optional<std::vector<std::byte>> ReadFile(const std::string &path)
{
    std::ifstream is{path, std::ios::binary | std::ios::ate};
    if (!is)
        return std::nullopt;

    auto size = is.tellg();
    std::vector<std::byte> contents(size);

    is.seekg(0);
    is.read((char *)contents.data(), size);

    if (contents.empty())
        return std::nullopt;
    return std::move(contents);
}

int main(int argc, const char **argv)
{
    std::cout << "CppND Capsstone Project!"
              << "\n";
    std::string osm_data_file = "";
    if (argc > 1)
    {
        // Get OSM file input from "-f" option
        for (int i = 1; i < argc; i++)
        {
            if (std::string_view{argv[i]} == "-f" && ++i < argc)
            {
                osm_data_file = argv[i];
            }
        }
    }
    else
    {
        std::cout << "To specify a map file use the following format:" << std::endl;
        std::cout << "Usage: [executable] [-f filename.osm]" << std::endl;
        std::cout << "Using default file: map.osm" << std::endl;
        osm_data_file = "../map.osm";
    }

    std::vector<std::byte> osm_data;
    if (osm_data.empty() && !osm_data_file.empty())
    {
        std::cout << "Reading OpenStreetMap data from the following file: " << osm_data_file << std::endl;
        auto data = ReadFile(osm_data_file);
        if (!data)
            std::cout << "Failed to read." << std::endl;
        else
            osm_data = std::move(*data);
    }

    // Build Model.
    RouteModel model{osm_data};

    // Render results of search.
    Render render{model};

    auto display = io2d::output_surface{400, 400, io2d::format::argb32, io2d::scaling::none, io2d::refresh_style::fixed, 30};
    display.size_change_callback([](io2d::output_surface &surface)
                                 { surface.dimensions(surface.display_dimensions()); });
    display.draw_callback([&](io2d::output_surface &surface)
                          { render.Display(surface); });
    display.begin_show();

    return 0;
}