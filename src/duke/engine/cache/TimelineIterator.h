/*
 * TimelineIterator.h
 *
 *  Created on: Feb 5, 2013
 *      Author: Guillaume Chatelet
 */

#pragma once

#include <duke/engine/Timeline.h>

namespace duke {

Ranges getMediaRanges(const Timeline &timeline);
bool contains(const Ranges &range, size_t frame);

struct TrackMediaFrameIterator {
	TrackMediaFrameIterator() = default;
	TrackMediaFrameIterator(const TrackMediaFrameIterator&) = default;
	TrackMediaFrameIterator(const Timeline * pTimeline, size_t currentFrame);

	void reset(const Timeline * pTimeline, size_t currentFrame);

	void clear();
	MediaFrameReference next();
	bool empty() const;
private:
	std::vector<MediaFrameReference> m_References;
};

enum class IterationMode
	: unsigned char {
		FORWARD, BACKWARD, PINGPONG
};

struct FrameIterator {
	FrameIterator(const Ranges *pMediaRanges, size_t initialFrame, IterationMode mode = IterationMode::FORWARD);

	FrameIterator& setMaxIterations(size_t maxIterations);

	void clear();
	size_t next();
	bool empty() const;
private:
	size_t findNext(size_t) const;
	size_t findPrevious(size_t) const;

	const Ranges *m_pMediaRanges;
	IterationMode m_Mode;
	size_t m_Forward, m_Backward, m_FramesToGo, m_SpanCount;
	bool m_bForward;
};

struct TimelineIterator {
	TimelineIterator();
	TimelineIterator(const Timeline * pTimeline, const Ranges *pMediaRanges, size_t currentFrame, IterationMode mode = IterationMode::FORWARD);

	inline void setMaxFrameIterations(size_t maxIterations) {
		m_FrameIterator.setMaxIterations(maxIterations);
	}

	void clear();
	MediaFrameReference next();
	bool empty();
private:
	const Timeline * m_pTimeline;
	FrameIterator m_FrameIterator;
	TrackMediaFrameIterator m_TrackIterator;
};

} /* namespace duke */
