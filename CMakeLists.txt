cmake_minimum_required(VERSION 3.20)

project(
  yalog
  VERSION 0.0.1
  DESCRIPTION "Yet another logger"
  LANGUAGES C)

add_library(yalog STATIC)
target_sources(yalog PRIVATE src/yalog.c)
target_include_directories(yalog PUBLIC src/)
