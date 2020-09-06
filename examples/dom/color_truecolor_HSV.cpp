// Copyright 2020 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.

#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/terminal.hpp>
#include <iostream>

#include "ftxui/screen/string.hpp"

int main(int argc, const char* argv[]) {
  using namespace ftxui;

  int saturation = 255;
  Elements array;
  for (int value = 0; value < 255; value += 10) {
    Elements line;
    for (int hue = 0; hue < 255; hue += 2)
      line.push_back(text(L" ") | bgcolor(Color::HSV(hue, saturation, value)));
    array.push_back(hbox(std::move(line)));
  }

  auto document = vbox(std::move(array));

  auto screen = Screen::Create(Dimension::Full(), Dimension::Fit(document));
  Render(screen, document);

  std::cout << screen.ToString();

  return 0;
}