// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: StageData.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_StageData_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_StageData_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3009000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3009002 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_StageData_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_StageData_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[3]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_StageData_2eproto;
class WholeStageData;
class WholeStageDataDefaultTypeInternal;
extern WholeStageDataDefaultTypeInternal _WholeStageData_default_instance_;
class WholeStageData_MapLine;
class WholeStageData_MapLineDefaultTypeInternal;
extern WholeStageData_MapLineDefaultTypeInternal _WholeStageData_MapLine_default_instance_;
class WholeStageData_Monster;
class WholeStageData_MonsterDefaultTypeInternal;
extern WholeStageData_MonsterDefaultTypeInternal _WholeStageData_Monster_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::WholeStageData* Arena::CreateMaybeMessage<::WholeStageData>(Arena*);
template<> ::WholeStageData_MapLine* Arena::CreateMaybeMessage<::WholeStageData_MapLine>(Arena*);
template<> ::WholeStageData_Monster* Arena::CreateMaybeMessage<::WholeStageData_Monster>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

// ===================================================================

class WholeStageData_MapLine :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:WholeStageData.MapLine) */ {
 public:
  WholeStageData_MapLine();
  virtual ~WholeStageData_MapLine();

  WholeStageData_MapLine(const WholeStageData_MapLine& from);
  WholeStageData_MapLine(WholeStageData_MapLine&& from) noexcept
    : WholeStageData_MapLine() {
    *this = ::std::move(from);
  }

  inline WholeStageData_MapLine& operator=(const WholeStageData_MapLine& from) {
    CopyFrom(from);
    return *this;
  }
  inline WholeStageData_MapLine& operator=(WholeStageData_MapLine&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const WholeStageData_MapLine& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const WholeStageData_MapLine* internal_default_instance() {
    return reinterpret_cast<const WholeStageData_MapLine*>(
               &_WholeStageData_MapLine_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(WholeStageData_MapLine& a, WholeStageData_MapLine& b) {
    a.Swap(&b);
  }
  inline void Swap(WholeStageData_MapLine* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline WholeStageData_MapLine* New() const final {
    return CreateMaybeMessage<WholeStageData_MapLine>(nullptr);
  }

  WholeStageData_MapLine* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<WholeStageData_MapLine>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const WholeStageData_MapLine& from);
  void MergeFrom(const WholeStageData_MapLine& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  #if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  #else
  bool MergePartialFromCodedStream(
      ::PROTOBUF_NAMESPACE_ID::io::CodedInputStream* input) final;
  #endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  void SerializeWithCachedSizes(
      ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream* output) const final;
  ::PROTOBUF_NAMESPACE_ID::uint8* InternalSerializeWithCachedSizesToArray(
      ::PROTOBUF_NAMESPACE_ID::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(WholeStageData_MapLine* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "WholeStageData.MapLine";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_StageData_2eproto);
    return ::descriptor_table_StageData_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kBlockFieldNumber = 1,
  };
  // repeated int32 block = 1;
  int block_size() const;
  void clear_block();
  ::PROTOBUF_NAMESPACE_ID::int32 block(int index) const;
  void set_block(int index, ::PROTOBUF_NAMESPACE_ID::int32 value);
  void add_block(::PROTOBUF_NAMESPACE_ID::int32 value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >&
      block() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >*
      mutable_block();

  // @@protoc_insertion_point(class_scope:WholeStageData.MapLine)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 > block_;
  mutable std::atomic<int> _block_cached_byte_size_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_StageData_2eproto;
};
// -------------------------------------------------------------------

class WholeStageData_Monster :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:WholeStageData.Monster) */ {
 public:
  WholeStageData_Monster();
  virtual ~WholeStageData_Monster();

  WholeStageData_Monster(const WholeStageData_Monster& from);
  WholeStageData_Monster(WholeStageData_Monster&& from) noexcept
    : WholeStageData_Monster() {
    *this = ::std::move(from);
  }

  inline WholeStageData_Monster& operator=(const WholeStageData_Monster& from) {
    CopyFrom(from);
    return *this;
  }
  inline WholeStageData_Monster& operator=(WholeStageData_Monster&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const WholeStageData_Monster& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const WholeStageData_Monster* internal_default_instance() {
    return reinterpret_cast<const WholeStageData_Monster*>(
               &_WholeStageData_Monster_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(WholeStageData_Monster& a, WholeStageData_Monster& b) {
    a.Swap(&b);
  }
  inline void Swap(WholeStageData_Monster* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline WholeStageData_Monster* New() const final {
    return CreateMaybeMessage<WholeStageData_Monster>(nullptr);
  }

  WholeStageData_Monster* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<WholeStageData_Monster>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const WholeStageData_Monster& from);
  void MergeFrom(const WholeStageData_Monster& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  #if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  #else
  bool MergePartialFromCodedStream(
      ::PROTOBUF_NAMESPACE_ID::io::CodedInputStream* input) final;
  #endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  void SerializeWithCachedSizes(
      ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream* output) const final;
  ::PROTOBUF_NAMESPACE_ID::uint8* InternalSerializeWithCachedSizesToArray(
      ::PROTOBUF_NAMESPACE_ID::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(WholeStageData_Monster* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "WholeStageData.Monster";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_StageData_2eproto);
    return ::descriptor_table_StageData_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kCommandsFieldNumber = 8,
    kStartYPosFieldNumber = 7,
    kTypeFieldNumber = 5,
    kStartXPosFieldNumber = 6,
  };
  // repeated int32 Commands = 8;
  int commands_size() const;
  void clear_commands();
  ::PROTOBUF_NAMESPACE_ID::int32 commands(int index) const;
  void set_commands(int index, ::PROTOBUF_NAMESPACE_ID::int32 value);
  void add_commands(::PROTOBUF_NAMESPACE_ID::int32 value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >&
      commands() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >*
      mutable_commands();

  // int32 startYPos = 7;
  void clear_startypos();
  ::PROTOBUF_NAMESPACE_ID::int32 startypos() const;
  void set_startypos(::PROTOBUF_NAMESPACE_ID::int32 value);

  // int32 Type = 5;
  void clear_type();
  ::PROTOBUF_NAMESPACE_ID::int32 type() const;
  void set_type(::PROTOBUF_NAMESPACE_ID::int32 value);

  // int32 startXPos = 6;
  void clear_startxpos();
  ::PROTOBUF_NAMESPACE_ID::int32 startxpos() const;
  void set_startxpos(::PROTOBUF_NAMESPACE_ID::int32 value);

  // @@protoc_insertion_point(class_scope:WholeStageData.Monster)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 > commands_;
  mutable std::atomic<int> _commands_cached_byte_size_;
  ::PROTOBUF_NAMESPACE_ID::int32 startypos_;
  ::PROTOBUF_NAMESPACE_ID::int32 type_;
  ::PROTOBUF_NAMESPACE_ID::int32 startxpos_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_StageData_2eproto;
};
// -------------------------------------------------------------------

class WholeStageData :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:WholeStageData) */ {
 public:
  WholeStageData();
  virtual ~WholeStageData();

  WholeStageData(const WholeStageData& from);
  WholeStageData(WholeStageData&& from) noexcept
    : WholeStageData() {
    *this = ::std::move(from);
  }

  inline WholeStageData& operator=(const WholeStageData& from) {
    CopyFrom(from);
    return *this;
  }
  inline WholeStageData& operator=(WholeStageData&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const WholeStageData& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const WholeStageData* internal_default_instance() {
    return reinterpret_cast<const WholeStageData*>(
               &_WholeStageData_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(WholeStageData& a, WholeStageData& b) {
    a.Swap(&b);
  }
  inline void Swap(WholeStageData* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline WholeStageData* New() const final {
    return CreateMaybeMessage<WholeStageData>(nullptr);
  }

  WholeStageData* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<WholeStageData>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const WholeStageData& from);
  void MergeFrom(const WholeStageData& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  #if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  #else
  bool MergePartialFromCodedStream(
      ::PROTOBUF_NAMESPACE_ID::io::CodedInputStream* input) final;
  #endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  void SerializeWithCachedSizes(
      ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream* output) const final;
  ::PROTOBUF_NAMESPACE_ID::uint8* InternalSerializeWithCachedSizesToArray(
      ::PROTOBUF_NAMESPACE_ID::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(WholeStageData* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "WholeStageData";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_StageData_2eproto);
    return ::descriptor_table_StageData_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  typedef WholeStageData_MapLine MapLine;
  typedef WholeStageData_Monster Monster;

  // accessors -------------------------------------------------------

  enum : int {
    kMapFieldNumber = 2,
    kMonstersFieldNumber = 9,
    kStageLevelFieldNumber = 1,
  };
  // repeated .WholeStageData.MapLine Map = 2;
  int map_size() const;
  void clear_map();
  ::WholeStageData_MapLine* mutable_map(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::WholeStageData_MapLine >*
      mutable_map();
  const ::WholeStageData_MapLine& map(int index) const;
  ::WholeStageData_MapLine* add_map();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::WholeStageData_MapLine >&
      map() const;

  // repeated .WholeStageData.Monster Monsters = 9;
  int monsters_size() const;
  void clear_monsters();
  ::WholeStageData_Monster* mutable_monsters(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::WholeStageData_Monster >*
      mutable_monsters();
  const ::WholeStageData_Monster& monsters(int index) const;
  ::WholeStageData_Monster* add_monsters();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::WholeStageData_Monster >&
      monsters() const;

  // int32 stage_level = 1;
  void clear_stage_level();
  ::PROTOBUF_NAMESPACE_ID::int32 stage_level() const;
  void set_stage_level(::PROTOBUF_NAMESPACE_ID::int32 value);

  // @@protoc_insertion_point(class_scope:WholeStageData)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::WholeStageData_MapLine > map_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::WholeStageData_Monster > monsters_;
  ::PROTOBUF_NAMESPACE_ID::int32 stage_level_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_StageData_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// WholeStageData_MapLine

// repeated int32 block = 1;
inline int WholeStageData_MapLine::block_size() const {
  return block_.size();
}
inline void WholeStageData_MapLine::clear_block() {
  block_.Clear();
}
inline ::PROTOBUF_NAMESPACE_ID::int32 WholeStageData_MapLine::block(int index) const {
  // @@protoc_insertion_point(field_get:WholeStageData.MapLine.block)
  return block_.Get(index);
}
inline void WholeStageData_MapLine::set_block(int index, ::PROTOBUF_NAMESPACE_ID::int32 value) {
  block_.Set(index, value);
  // @@protoc_insertion_point(field_set:WholeStageData.MapLine.block)
}
inline void WholeStageData_MapLine::add_block(::PROTOBUF_NAMESPACE_ID::int32 value) {
  block_.Add(value);
  // @@protoc_insertion_point(field_add:WholeStageData.MapLine.block)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >&
WholeStageData_MapLine::block() const {
  // @@protoc_insertion_point(field_list:WholeStageData.MapLine.block)
  return block_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >*
WholeStageData_MapLine::mutable_block() {
  // @@protoc_insertion_point(field_mutable_list:WholeStageData.MapLine.block)
  return &block_;
}

// -------------------------------------------------------------------

// WholeStageData_Monster

// int32 Type = 5;
inline void WholeStageData_Monster::clear_type() {
  type_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 WholeStageData_Monster::type() const {
  // @@protoc_insertion_point(field_get:WholeStageData.Monster.Type)
  return type_;
}
inline void WholeStageData_Monster::set_type(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  type_ = value;
  // @@protoc_insertion_point(field_set:WholeStageData.Monster.Type)
}

// int32 startXPos = 6;
inline void WholeStageData_Monster::clear_startxpos() {
  startxpos_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 WholeStageData_Monster::startxpos() const {
  // @@protoc_insertion_point(field_get:WholeStageData.Monster.startXPos)
  return startxpos_;
}
inline void WholeStageData_Monster::set_startxpos(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  startxpos_ = value;
  // @@protoc_insertion_point(field_set:WholeStageData.Monster.startXPos)
}

// int32 startYPos = 7;
inline void WholeStageData_Monster::clear_startypos() {
  startypos_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 WholeStageData_Monster::startypos() const {
  // @@protoc_insertion_point(field_get:WholeStageData.Monster.startYPos)
  return startypos_;
}
inline void WholeStageData_Monster::set_startypos(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  startypos_ = value;
  // @@protoc_insertion_point(field_set:WholeStageData.Monster.startYPos)
}

// repeated int32 Commands = 8;
inline int WholeStageData_Monster::commands_size() const {
  return commands_.size();
}
inline void WholeStageData_Monster::clear_commands() {
  commands_.Clear();
}
inline ::PROTOBUF_NAMESPACE_ID::int32 WholeStageData_Monster::commands(int index) const {
  // @@protoc_insertion_point(field_get:WholeStageData.Monster.Commands)
  return commands_.Get(index);
}
inline void WholeStageData_Monster::set_commands(int index, ::PROTOBUF_NAMESPACE_ID::int32 value) {
  commands_.Set(index, value);
  // @@protoc_insertion_point(field_set:WholeStageData.Monster.Commands)
}
inline void WholeStageData_Monster::add_commands(::PROTOBUF_NAMESPACE_ID::int32 value) {
  commands_.Add(value);
  // @@protoc_insertion_point(field_add:WholeStageData.Monster.Commands)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >&
WholeStageData_Monster::commands() const {
  // @@protoc_insertion_point(field_list:WholeStageData.Monster.Commands)
  return commands_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >*
WholeStageData_Monster::mutable_commands() {
  // @@protoc_insertion_point(field_mutable_list:WholeStageData.Monster.Commands)
  return &commands_;
}

// -------------------------------------------------------------------

// WholeStageData

// int32 stage_level = 1;
inline void WholeStageData::clear_stage_level() {
  stage_level_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 WholeStageData::stage_level() const {
  // @@protoc_insertion_point(field_get:WholeStageData.stage_level)
  return stage_level_;
}
inline void WholeStageData::set_stage_level(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  stage_level_ = value;
  // @@protoc_insertion_point(field_set:WholeStageData.stage_level)
}

// repeated .WholeStageData.MapLine Map = 2;
inline int WholeStageData::map_size() const {
  return map_.size();
}
inline void WholeStageData::clear_map() {
  map_.Clear();
}
inline ::WholeStageData_MapLine* WholeStageData::mutable_map(int index) {
  // @@protoc_insertion_point(field_mutable:WholeStageData.Map)
  return map_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::WholeStageData_MapLine >*
WholeStageData::mutable_map() {
  // @@protoc_insertion_point(field_mutable_list:WholeStageData.Map)
  return &map_;
}
inline const ::WholeStageData_MapLine& WholeStageData::map(int index) const {
  // @@protoc_insertion_point(field_get:WholeStageData.Map)
  return map_.Get(index);
}
inline ::WholeStageData_MapLine* WholeStageData::add_map() {
  // @@protoc_insertion_point(field_add:WholeStageData.Map)
  return map_.Add();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::WholeStageData_MapLine >&
WholeStageData::map() const {
  // @@protoc_insertion_point(field_list:WholeStageData.Map)
  return map_;
}

// repeated .WholeStageData.Monster Monsters = 9;
inline int WholeStageData::monsters_size() const {
  return monsters_.size();
}
inline void WholeStageData::clear_monsters() {
  monsters_.Clear();
}
inline ::WholeStageData_Monster* WholeStageData::mutable_monsters(int index) {
  // @@protoc_insertion_point(field_mutable:WholeStageData.Monsters)
  return monsters_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::WholeStageData_Monster >*
WholeStageData::mutable_monsters() {
  // @@protoc_insertion_point(field_mutable_list:WholeStageData.Monsters)
  return &monsters_;
}
inline const ::WholeStageData_Monster& WholeStageData::monsters(int index) const {
  // @@protoc_insertion_point(field_get:WholeStageData.Monsters)
  return monsters_.Get(index);
}
inline ::WholeStageData_Monster* WholeStageData::add_monsters() {
  // @@protoc_insertion_point(field_add:WholeStageData.Monsters)
  return monsters_.Add();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::WholeStageData_Monster >&
WholeStageData::monsters() const {
  // @@protoc_insertion_point(field_list:WholeStageData.Monsters)
  return monsters_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_StageData_2eproto
