#pragma once

#include <string>
#include "properties.h"

namespace network_io
{
	class server_config : public properties
	{
	public:
		server_config(const std::string& path);
		~server_config();

		unsigned short port() const;
		int pool_size() const;
		std::string root() const;

	private:
		static const std::string KEY_PORT;
		static const std::string KEY_POOL_SIZE;
		static const std::string KEY_FILE_MANAGER_ROOT;

		static const unsigned short DEFAULT_PORT;
		static const int DEFAULT_POOL_SIZE;

		unsigned short port_;
		int pool_size_;
		std::string root_;
	};
}