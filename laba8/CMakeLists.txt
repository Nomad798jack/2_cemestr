cmake_minimum_required(VERSION 3.15) # Проверка версии CMake.
									 # Если версия установленой программы
									 # старее указаной, произайдёт аварийный выход.

set(PROJECT_NAME Bongobongo)				 # имя проекта		 
project(Bongobongo)


set(CMAKE_CXX_STANDARD 17)			 # устанавливаем 17 стандарт языка

add_definitions(-DSFML_STATIC)		 # дефайны

include_directories("SEFEMEL/SFML/include/")	# добавляем директории
include_directories("inc/")
link_directories("SEFEMEL/SFML/lib/")	

add_executable(Bongobongo Bongobongo.cpp
		
)
											
target_link_libraries(Bongobongo sfml-graphics-s-d
						  sfml-window-s-d
						  sfml-system-s-d
						  opengl32
						  freetype
						  winmm
						  gdi32
						  sfml-audio-s-d
						  openal32
						  flac
						  vorbisenc
						  vorbisfile
						  vorbis
						  ogg)