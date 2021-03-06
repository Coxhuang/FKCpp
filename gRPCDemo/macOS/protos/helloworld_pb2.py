# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: helloworld.proto

import sys
_b=sys.version_info[0]<3 and (lambda x:x) or (lambda x:x.encode('latin1'))
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor.FileDescriptor(
  name='helloworld.proto',
  package='helloworld',
  syntax='proto3',
  serialized_options=_b('\n\007ex.grpc'),
  serialized_pb=_b('\n\x10helloworld.proto\x12\nhelloworld\"\x17\n\x05Reply\x12\x0e\n\x06result\x18\x01 \x01(\x05\"$\n\x0cHelloMessage\x12\t\n\x01\x61\x18\x01 \x01(\x05\x12\t\n\x01\x62\x18\x02 \x01(\x05\x32\x89\x01\n\nTestServer\x12>\n\rhello_request\x12\x18.helloworld.HelloMessage\x1a\x11.helloworld.Reply\"\x00\x12;\n\nhello_test\x12\x18.helloworld.HelloMessage\x1a\x11.helloworld.Reply\"\x00\x42\t\n\x07\x65x.grpcb\x06proto3')
)




_REPLY = _descriptor.Descriptor(
  name='Reply',
  full_name='helloworld.Reply',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='result', full_name='helloworld.Reply.result', index=0,
      number=1, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=32,
  serialized_end=55,
)


_HELLOMESSAGE = _descriptor.Descriptor(
  name='HelloMessage',
  full_name='helloworld.HelloMessage',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='a', full_name='helloworld.HelloMessage.a', index=0,
      number=1, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='b', full_name='helloworld.HelloMessage.b', index=1,
      number=2, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=57,
  serialized_end=93,
)

DESCRIPTOR.message_types_by_name['Reply'] = _REPLY
DESCRIPTOR.message_types_by_name['HelloMessage'] = _HELLOMESSAGE
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

Reply = _reflection.GeneratedProtocolMessageType('Reply', (_message.Message,), {
  'DESCRIPTOR' : _REPLY,
  '__module__' : 'helloworld_pb2'
  # @@protoc_insertion_point(class_scope:helloworld.Reply)
  })
_sym_db.RegisterMessage(Reply)

HelloMessage = _reflection.GeneratedProtocolMessageType('HelloMessage', (_message.Message,), {
  'DESCRIPTOR' : _HELLOMESSAGE,
  '__module__' : 'helloworld_pb2'
  # @@protoc_insertion_point(class_scope:helloworld.HelloMessage)
  })
_sym_db.RegisterMessage(HelloMessage)


DESCRIPTOR._options = None

_TESTSERVER = _descriptor.ServiceDescriptor(
  name='TestServer',
  full_name='helloworld.TestServer',
  file=DESCRIPTOR,
  index=0,
  serialized_options=None,
  serialized_start=96,
  serialized_end=233,
  methods=[
  _descriptor.MethodDescriptor(
    name='hello_request',
    full_name='helloworld.TestServer.hello_request',
    index=0,
    containing_service=None,
    input_type=_HELLOMESSAGE,
    output_type=_REPLY,
    serialized_options=None,
  ),
  _descriptor.MethodDescriptor(
    name='hello_test',
    full_name='helloworld.TestServer.hello_test',
    index=1,
    containing_service=None,
    input_type=_HELLOMESSAGE,
    output_type=_REPLY,
    serialized_options=None,
  ),
])
_sym_db.RegisterServiceDescriptor(_TESTSERVER)

DESCRIPTOR.services_by_name['TestServer'] = _TESTSERVER

# @@protoc_insertion_point(module_scope)
