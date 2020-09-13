#ifndef SORT_FILES_H
#define SORT_FILES_H

#include <chrono>
#include <filesystem>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

class sort_files {
public:
  explicit sort_files(std::filesystem::path curr_path)
      : curr_path(std::move(curr_path)) {}

  void start();

  int count_f() const;

private:
  static const std::unordered_map<std::string_view, std::string_view> ext_to_dest;
  static const std::unordered_map<std::string_view, int> month_to_quarter;

  // fields
  int f_counter{0};
  std::filesystem::path curr_path{};

  // methods
  bool has_ext(const std::string_view &f_ext,
               const std::vector<std::string_view> &exts);
  int quarter_num(const std::string_view &month);

  std::vector<std::string_view> f_extensions();

  std::string_view dest_folder(const std::string_view &ext);

  std::filesystem::path res_dest_path(const std::string_view &dest_folder,
                                      const std::string_view &year,
                                      const std::string_view &quarter);

  std::pair<std::string, std::string>
  year_and_month(const std::filesystem::directory_entry &file);

  void
  f_print(const std::filesystem::path &f_path, const std::string_view &year,
          const std::string_view &month, const std::string_view &quarter);

  template<typename TP>
  std::time_t to_time_t(TP tp);
};

#endif // SORT_FILES_H
