/*
 * PboPool.h
 *
 *  Created on: Feb 15, 2013
 *      Author: Guillaume Chatelet
 */

#pragma once

#include <duke/engine/cache/Pool.h>
#include <duke/gl/GlObjects.h>
#include <duke/imageio/PackedFrameDescription.h>
#include <map>
#include <cstdio>

namespace duke {

struct PboPoolPolicy: public pool::PoolBase<size_t, gl::GlStreamUploadPbo> {
protected:
	value_type* evictAndCreate(const key_type& key, PoolMap &map) {
		auto *pValue = new gl::GlStreamUploadPbo();
		{
			auto boundBuffer = pValue->scope_bind_buffer();
			glBufferData(pValue->target, key, 0, pValue->usage);
		}
		m_KeyMap[pValue] = key;
		size += key;
		return pValue;
	}

	key_type retrieveKey(const value_type* pData) {
		return m_KeyMap[pData];
	}
private:
	std::map<const value_type*, key_type> m_KeyMap;
public:
	size_t size = 0;
};

typedef pool::Pool<PboPoolPolicy> PboPool;
typedef PboPool::DataPtr SharedPbo;

} /* namespace duke */
