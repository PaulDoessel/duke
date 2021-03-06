Duke version 2.0
================

Duke is an **opensource high resolution image and sequence viewer** dedicated to visual effect and post production companies.


Current features
----------------

* image viewer / sequence player
* look ahead cache with multithreaded load/decode
* `space` : play pause
* `left` `right` : go to previous/next frame (hold `Ctrl` to jump 25 frames)
* `+` `-` `*` : increase/decrease/reset exposure
* `o` : show/hide metadata
* `f` : cycle through fit mode ( actual, fit inner, fit outer )
* `s` : display/hide cache state, framerate
* `home` `end` : go to begin, end of playlist
* `r` `g` `b` `a` : toggle R/G/B/A filter channel
* mouse drag and mouse wheel to pan/zoom
* colorspace is autodetected from image metadata or filename extension


We aim at
---------

* support for Look Up Tables
* split view to compare tracks
* basic color grading
* movie playback
* recording to file sequences or movies
* sound support
* 3D support


Compilation
-----------

* Getting the source

> git clone --recursive https://github.com/mikrosimage/duke.git  

* Compilation

    see INSTALL file


Tested compilers
----------------

* G++ 4.7.1 on OpenSUSE 12.2
* G++ 4.7.2 on Gentoo


More informations 
-----------------

* Duke public repository
http://github.com/mikrosimage/duke

* The github issues module for bug report
https://github.com/mikrosimage/duke/issues


License
-------

    see COPYING file


Credits
-------

Duke has been initiated by HD3D² R&D project, sustained by Cap Digital, the French business cluster for digital content and services.

The project is maintained as an open source project by [Mikros Image](http://www.mikrosimage.eu).

Duke uses
* [GLFW](https://github.com/elmindreda/glfw)
* [GLM](https://github.com/Groovounet/glm)
* [concurrent_utils](https://github.com/mikrosimage/concurrent_utils)
* [light_sequence_parser](https://github.com/gchatelet/light_sequence_parser)
