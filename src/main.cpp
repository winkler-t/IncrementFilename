#include <iostream>
#include <cstdio>
#include <cstdio>
#include <filesystem>
#include <string.h>
#include <vector>
#include <tuple>
#include <algorithm>

#define VALDEFCOUNT 2

std::string valdefs[VALDEFCOUNT] = {"-d", "-s"};

long long index_start = 0;
std::filesystem::path dir;
std::vector<std::filesystem::path> files;

std::filesystem::path start_workdir;

void rename_file(std::filesystem::path file, std::filesystem::path new_name)
{
    std::filesystem::rename(file, new_name);
}

void rename_all_files()
{
    while (files.size() > 0)
    {
        std::filesystem::path new_path(files.back());
        new_path.replace_filename(std::to_string(index_start));
        new_path.replace_extension(files.back().extension());
        std::cout << "File: " << files.back().filename().string() << " to: " << new_path.filename().string() << std::endl;
        rename_file(files.back(), new_path);
        files.pop_back();
        index_start++;
    }
}

int main(int argc, char *argv[])
{
    start_workdir = std::filesystem::current_path();

    for (size_t i = 0; i < argc - 1; i++)
    {
        std::string current_arg(argv[i]);
        std::string next_arg(argv[i + 1]);
        if (argv[i][0] != '-')
            continue;

        for (size_t j = 0; j < VALDEFCOUNT; j++)
        {
            if (current_arg == valdefs[0])
            {
                if (!std::filesystem::exists(next_arg))
                {
                    std::cerr << "Directory does not exist!" << std::endl;
                    return false;
                }

                dir = std::filesystem::path(next_arg);

                for (const auto &file : std::filesystem::directory_iterator(dir))
                {
                    if ((std::find(files.begin(),files.end(), file.path().filename()) == files.end()))
                        files.push_back(file.path().filename());
                }
            }
            if (current_arg == valdefs[1])
                index_start = std::stoll(next_arg);
        }
    }
    if (argc <= 1)
        dir = start_workdir;

    std::filesystem::current_path(dir);
    rename_all_files();
    std::filesystem::current_path(start_workdir);

    return 0;
}