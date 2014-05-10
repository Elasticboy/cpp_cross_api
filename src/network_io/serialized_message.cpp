#include "serialized_message.h"

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>

namespace network_io {

	// Build the request from the serialized message.
	Request build_request(const serialized_message& message)
	{
		Request request;
		// Read varint delimited protobuf object in the buffer
		google::protobuf::io::ArrayInputStream arrayInputStream(message.buffer(), message.size());
		google::protobuf::io::CodedInputStream codedInputStream(&arrayInputStream);

		google::protobuf::uint32 size;
		codedInputStream.ReadVarint32(&size);
		google::protobuf::io::CodedInputStream::Limit msgLimit = codedInputStream.PushLimit(size);

		request.ParseFromCodedStream(&codedInputStream);
		codedInputStream.PopLimit(msgLimit);

		return request;
	}

	// Serializes the response 
	serialized_message serialize_response(const Response& response)
	{
		// Build a buffer that can hold message and room for a 32bit delimiter
		auto bufSize	= response.ByteSize() + 4;
		char* buf	= new char [bufSize];

		// Write varint delimiter to the buffer
		google::protobuf::io::ArrayOutputStream arrayOutputStream(buf, bufSize);
		google::protobuf::io::CodedOutputStream codedOutputStream(&arrayOutputStream);
		codedOutputStream.WriteVarint32(response.ByteSize());
		
		// Write response to the buffer
		response.SerializeToCodedStream(&codedOutputStream);

		serialized_message message(buf, bufSize);
		return message;
	}
	
	// Clears the response from potential errors before retrying serialization
	Response clear_response(Response& response, const std::string& message)
	{
		response.set_returncode(Response_ReturnCode_RC_ERROR);
		response.clear_message();
		if (!message.empty()) {
			response.set_message(message);
		}
		response.clear_intvalue();
		response.clear_file();

		return response;
	}

}