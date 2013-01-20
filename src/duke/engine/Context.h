/*
 * Context.h
 *
 *  Created on: Jan 4, 2013
 *      Author: Guillaume Chatelet
 */

#ifndef CONTEXT_H_
#define CONTEXT_H_

#include "DukeWindow.h"
#include <duke/time/FrameUtils.h>
#include <glm/glm.hpp>

class Attributes;

namespace duke {

class ITexture;

struct Context {
	Viewport viewport;
	Time liveTime;
	Time playbackTime;
	FrameIndex currentFrame;
	size_t clipFrame = 0;
	int zoom = 1;
	glm::ivec2 pan;
	glm::bvec4 channels = glm::bvec4(false);
	float exposure = 1;
	std::function<void(const ITexture&, const Attributes&)> renderTexture;
};

} /* namespace duke */
#endif /* CONTEXT_H_ */