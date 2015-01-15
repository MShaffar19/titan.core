///////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2000-2014 Ericsson Telecom AB
// All rights reserved. This program and the accompanying materials
// are made available under the terms of the Eclipse Public License v1.0
// which accompanies this distribution, and is available at
// http://www.eclipse.org/legal/epl-v10.html
///////////////////////////////////////////////////////////////////////////////
#ifndef ASN_CharacterString_HH
#define ASN_CharacterString_HH

#include "Types.h"
#include "Basetype.hh"
#include "Template.hh"

#include "ASN_Null.hh"
#include "Integer.hh"
#include "Objid.hh"
#include "Charstring.hh"
#include "Universal_charstring.hh"
#include "Octetstring.hh"

class CHARACTER_STRING_identification;
class CHARACTER_STRING_identification_template;
class CHARACTER_STRING_identification_syntaxes;
class CHARACTER_STRING_identification_syntaxes_template;
class CHARACTER_STRING_identification_context__negotiation;
class CHARACTER_STRING_identification_context__negotiation_template;
class CHARACTER_STRING;
class CHARACTER_STRING_template;

class Module_Param;

class CHARACTER_STRING_identification : public Base_Type {
public:
  enum union_selection_type { UNBOUND_VALUE = 0, ALT_syntaxes = 1, ALT_syntax = 2, ALT_presentation__context__id = 3, ALT_context__negotiation = 4, ALT_transfer__syntax = 5, ALT_fixed = 6 };
private:
  union_selection_type union_selection;
  union {
    CHARACTER_STRING_identification_syntaxes *field_syntaxes;
    OBJID *field_syntax;
    INTEGER *field_presentation__context__id;
    CHARACTER_STRING_identification_context__negotiation *field_context__negotiation;
    OBJID *field_transfer__syntax;
    ASN_NULL *field_fixed;
  };
  void copy_value(const CHARACTER_STRING_identification& other_value);

public:
  CHARACTER_STRING_identification();
  CHARACTER_STRING_identification(const CHARACTER_STRING_identification& other_value);
  ~CHARACTER_STRING_identification();
  CHARACTER_STRING_identification& operator=(const CHARACTER_STRING_identification& other_value);
  boolean operator==(const CHARACTER_STRING_identification& other_value) const;
  inline boolean operator!=(const CHARACTER_STRING_identification& other_value) const { return !(*this == other_value); }
  CHARACTER_STRING_identification_syntaxes& syntaxes();
  const CHARACTER_STRING_identification_syntaxes& syntaxes() const;
  OBJID& syntax();
  const OBJID& syntax() const;
  INTEGER& presentation__context__id();
  const INTEGER& presentation__context__id() const;
  CHARACTER_STRING_identification_context__negotiation& context__negotiation();
  const CHARACTER_STRING_identification_context__negotiation& context__negotiation() const;
  OBJID& transfer__syntax();
  const OBJID& transfer__syntax() const;
  ASN_NULL& fixed();
  const ASN_NULL& fixed() const;
  inline union_selection_type get_selection() const { return union_selection; }
  boolean ischosen(union_selection_type checked_selection) const;
  boolean is_bound() const;
  boolean is_value() const;
  void clean_up();
  void log() const;
#ifdef TITAN_RUNTIME_2
  boolean is_equal(const Base_Type* other_value) const { return *this == *(static_cast<const CHARACTER_STRING_identification*>(other_value)); }
  void set_value(const Base_Type* other_value) { *this = *(static_cast<const CHARACTER_STRING_identification*>(other_value)); }
  Base_Type* clone() const { return new CHARACTER_STRING_identification(*this); }
  const TTCN_Typedescriptor_t* get_descriptor() const { return &CHARACTER_STRING_descr_; }
#else
  inline boolean is_present() const { return is_bound(); }
#endif
  void set_param(Module_Param& param);
  void encode_text(Text_Buf& text_buf) const;
  void decode_text(Text_Buf& text_buf);
  //void encode(const TTCN_Typedescriptor_t& p_td, TTCN_Buffer& p_buf, TTCN_EncDec::coding_t p_coding, ...) const;
  //void decode(const TTCN_Typedescriptor_t& p_td, TTCN_Buffer& p_buf, TTCN_EncDec::coding_t p_coding, ...);
  ASN_BER_TLV_t* BER_encode_TLV(const TTCN_Typedescriptor_t& p_td, unsigned p_coding) const;
  boolean BER_decode_TLV(const TTCN_Typedescriptor_t& p_td, const ASN_BER_TLV_t& p_tlv, unsigned L_form);
  int XER_encode(const XERdescriptor_t& p_td,
                 TTCN_Buffer& p_buf, unsigned int flavor, int indent) const;
  int XER_decode(const XERdescriptor_t& p_td,
                 XmlReaderWrap& reader, unsigned int flavor);
private:
  boolean BER_decode_set_selection(const ASN_BER_TLV_t& p_tlv);
public:
  boolean BER_decode_isMyMsg(const TTCN_Typedescriptor_t& p_td, const ASN_BER_TLV_t& p_tlv);
};

class CHARACTER_STRING_identification_template : public Base_Template {
  union {
    struct {
      CHARACTER_STRING_identification::union_selection_type union_selection;
      union {
	CHARACTER_STRING_identification_syntaxes_template *field_syntaxes;
	OBJID_template *field_syntax;
	INTEGER_template *field_presentation__context__id;
	CHARACTER_STRING_identification_context__negotiation_template *field_context__negotiation;
	OBJID_template *field_transfer__syntax;
	ASN_NULL_template *field_fixed;
      };
    } single_value;
    struct {
      unsigned int n_values;
      CHARACTER_STRING_identification_template *list_value;
    } value_list;
  };

  void copy_value(const CHARACTER_STRING_identification& other_value);

  void copy_template(const CHARACTER_STRING_identification_template& other_value);

public:
  CHARACTER_STRING_identification_template();
  CHARACTER_STRING_identification_template(template_sel other_value);
  CHARACTER_STRING_identification_template(const CHARACTER_STRING_identification& other_value);
  CHARACTER_STRING_identification_template(const OPTIONAL<CHARACTER_STRING_identification>& other_value);
  CHARACTER_STRING_identification_template(const CHARACTER_STRING_identification_template& other_value);
  ~CHARACTER_STRING_identification_template();
  void clean_up();
  CHARACTER_STRING_identification_template& operator=(template_sel other_value);
  CHARACTER_STRING_identification_template& operator=(const CHARACTER_STRING_identification& other_value);
  CHARACTER_STRING_identification_template& operator=(const OPTIONAL<CHARACTER_STRING_identification>& other_value);
  CHARACTER_STRING_identification_template& operator=(const CHARACTER_STRING_identification_template& other_value);
  boolean match(const CHARACTER_STRING_identification& other_value) const;
  CHARACTER_STRING_identification valueof() const;
  CHARACTER_STRING_identification_template& list_item(unsigned int list_index) const;
  void set_type(template_sel template_type, unsigned int list_length);
  CHARACTER_STRING_identification_syntaxes_template& syntaxes();
  const CHARACTER_STRING_identification_syntaxes_template& syntaxes() const;
  OBJID_template& syntax();
  const OBJID_template& syntax() const;
  INTEGER_template& presentation__context__id();
  const INTEGER_template& presentation__context__id() const;
  CHARACTER_STRING_identification_context__negotiation_template& context__negotiation();
  const CHARACTER_STRING_identification_context__negotiation_template& context__negotiation() const;
  OBJID_template& transfer__syntax();
  const OBJID_template& transfer__syntax() const;
  ASN_NULL_template& fixed();
  const ASN_NULL_template& fixed() const;
  boolean ischosen(CHARACTER_STRING_identification::union_selection_type checked_selection) const;
  void log() const;
  void log_match(const CHARACTER_STRING_identification& match_value) const;
  void encode_text(Text_Buf& text_buf) const;
  void decode_text(Text_Buf& text_buf);

  boolean is_present() const;
  boolean match_omit() const;
  void set_param(Module_Param& param);
#ifdef TITAN_RUNTIME_2
  void valueofv(Base_Type* value) const { *(static_cast<CHARACTER_STRING_identification*>(value)) = valueof(); }
  void set_value(template_sel other_value) { *this = other_value; }
  void copy_value(const Base_Type* other_value) { *this = *(static_cast<const CHARACTER_STRING_identification*>(other_value)); }
  Base_Template* clone() const { return new CHARACTER_STRING_identification_template(*this); }
  const TTCN_Typedescriptor_t* get_descriptor() const { return &CHARACTER_STRING_descr_; }
  boolean matchv(const Base_Type* other_value) const { return match(*(static_cast<const CHARACTER_STRING_identification*>(other_value))); }
  void log_matchv(const Base_Type* match_value) const  { log_match(*(static_cast<const CHARACTER_STRING_identification*>(match_value))); }
#else
  void check_restriction(template_res t_res, const char* t_name=NULL) const;
#endif
};

class CHARACTER_STRING_identification_syntaxes : public Base_Type {
  OBJID field_abstract;
  OBJID field_transfer;
public:
  CHARACTER_STRING_identification_syntaxes();
  CHARACTER_STRING_identification_syntaxes(const OBJID& par_abstract,
					   const OBJID& par_transfer);
  boolean operator==(const CHARACTER_STRING_identification_syntaxes& other_value) const;
  inline boolean operator!=(const CHARACTER_STRING_identification_syntaxes& other_value) const
  { return !(*this == other_value); }

  inline OBJID& abstract()
  {return field_abstract;}
  inline const OBJID& abstract() const
  {return field_abstract;}
  inline OBJID& transfer()
  {return field_transfer;}
  inline const OBJID& transfer() const
  {return field_transfer;}
  int size_of() const;
  void log() const;
#ifdef TITAN_RUNTIME_2
  boolean is_equal(const Base_Type* other_value) const { return *this == *(static_cast<const CHARACTER_STRING_identification_syntaxes*>(other_value)); }
  void set_value(const Base_Type* other_value) { *this = *(static_cast<const CHARACTER_STRING_identification_syntaxes*>(other_value)); }
  Base_Type* clone() const { return new CHARACTER_STRING_identification_syntaxes(*this); }
  const TTCN_Typedescriptor_t* get_descriptor() const { return &CHARACTER_STRING_descr_; }
#else
  inline boolean is_present() const { return is_bound(); }
#endif
  boolean is_bound() const;
  boolean is_value() const;
  void clean_up();
  void set_param(Module_Param& param);
  void encode_text(Text_Buf& text_buf) const;
  void decode_text(Text_Buf& text_buf);
  //void encode(const TTCN_Typedescriptor_t& p_td, TTCN_Buffer& p_buf, TTCN_EncDec::coding_t p_coding, ...) const;
  //void decode(const TTCN_Typedescriptor_t& p_td, TTCN_Buffer& p_buf, TTCN_EncDec::coding_t p_coding, ...);
  ASN_BER_TLV_t* BER_encode_TLV(const TTCN_Typedescriptor_t& p_td, unsigned p_coding) const;
  boolean BER_decode_TLV(const TTCN_Typedescriptor_t& p_td, const ASN_BER_TLV_t& p_tlv, unsigned L_form);
  int XER_encode(const XERdescriptor_t& p_td,
                 TTCN_Buffer& p_buf, unsigned int flavor, int indent) const;
  int XER_decode(const XERdescriptor_t& p_td,
                 XmlReaderWrap& reader, unsigned int flavor);
};

class CHARACTER_STRING_identification_syntaxes_template : public Base_Template {
#ifdef __SUNPRO_CC
 public:
#endif
  struct single_value_struct;
#ifdef __SUNPRO_CC
 private:
#endif
  union {
    single_value_struct *single_value;
    struct {
      unsigned int n_values;
      CHARACTER_STRING_identification_syntaxes_template *list_value;
    } value_list;
  };

  void set_specific();
  void copy_value(const CHARACTER_STRING_identification_syntaxes& other_value);
  void copy_template(const CHARACTER_STRING_identification_syntaxes_template& other_value);

public:
  CHARACTER_STRING_identification_syntaxes_template();
  CHARACTER_STRING_identification_syntaxes_template(template_sel other_value);
  CHARACTER_STRING_identification_syntaxes_template(const CHARACTER_STRING_identification_syntaxes& other_value);
  CHARACTER_STRING_identification_syntaxes_template(const OPTIONAL<CHARACTER_STRING_identification_syntaxes>& other_value);
  CHARACTER_STRING_identification_syntaxes_template(const CHARACTER_STRING_identification_syntaxes_template& other_value);
  ~CHARACTER_STRING_identification_syntaxes_template();
  void clean_up();
  CHARACTER_STRING_identification_syntaxes_template& operator=(template_sel other_value);
  CHARACTER_STRING_identification_syntaxes_template& operator=(const CHARACTER_STRING_identification_syntaxes& other_value);
  CHARACTER_STRING_identification_syntaxes_template& operator=(const OPTIONAL<CHARACTER_STRING_identification_syntaxes>& other_value);
  CHARACTER_STRING_identification_syntaxes_template& operator=(const CHARACTER_STRING_identification_syntaxes_template& other_value);
  boolean match(const CHARACTER_STRING_identification_syntaxes& other_value) const;
  CHARACTER_STRING_identification_syntaxes valueof() const;
  void set_type(template_sel template_type, unsigned int list_length);
  CHARACTER_STRING_identification_syntaxes_template& list_item(unsigned int list_index) const;
  OBJID_template& abstract();
  const OBJID_template& abstract() const;
  OBJID_template& transfer();
  const OBJID_template& transfer() const;
  int size_of() const;
  void log() const;
  void log_match(const CHARACTER_STRING_identification_syntaxes& match_value) const;
  void encode_text(Text_Buf& text_buf) const;
  void decode_text(Text_Buf& text_buf);

  boolean is_present() const;
  boolean match_omit() const;
  void set_param(Module_Param& param);
#ifdef TITAN_RUNTIME_2
  void valueofv(Base_Type* value) const { *(static_cast<CHARACTER_STRING_identification_syntaxes*>(value)) = valueof(); }
  void set_value(template_sel other_value) { *this = other_value; }
  void copy_value(const Base_Type* other_value) { *this = *(static_cast<const CHARACTER_STRING_identification_syntaxes*>(other_value)); }
  Base_Template* clone() const { return new CHARACTER_STRING_identification_syntaxes_template(*this); }
  const TTCN_Typedescriptor_t* get_descriptor() const { return &CHARACTER_STRING_descr_; }
  boolean matchv(const Base_Type* other_value) const { return match(*(static_cast<const CHARACTER_STRING_identification_syntaxes*>(other_value))); }
  void log_matchv(const Base_Type* match_value) const  { log_match(*(static_cast<const CHARACTER_STRING_identification_syntaxes*>(match_value))); }
#else
  void check_restriction(template_res t_res, const char* t_name=NULL) const;
#endif
};

class CHARACTER_STRING_identification_context__negotiation : public Base_Type {
  INTEGER field_presentation__context__id;
  OBJID field_transfer__syntax;
public:
  CHARACTER_STRING_identification_context__negotiation();
  CHARACTER_STRING_identification_context__negotiation(const INTEGER& par_presentation__context__id,
						       const OBJID& par_transfer__syntax);
  boolean operator==(const CHARACTER_STRING_identification_context__negotiation& other_value) const;
  inline boolean operator!=(const CHARACTER_STRING_identification_context__negotiation& other_value) const
  { return !(*this == other_value); }

  inline INTEGER& presentation__context__id()
  {return field_presentation__context__id;}
  inline const INTEGER& presentation__context__id() const
  {return field_presentation__context__id;}
  inline OBJID& transfer__syntax()
  {return field_transfer__syntax;}
  inline const OBJID& transfer__syntax() const
  {return field_transfer__syntax;}
  int size_of() const;
  void log() const;
  boolean is_bound() const;
  boolean is_value() const;
  void clean_up();
#ifdef TITAN_RUNTIME_2
  boolean is_equal(const Base_Type* other_value) const { return *this == *(static_cast<const CHARACTER_STRING_identification_context__negotiation*>(other_value)); }
  void set_value(const Base_Type* other_value) { *this = *(static_cast<const CHARACTER_STRING_identification_context__negotiation*>(other_value)); }
  Base_Type* clone() const { return new CHARACTER_STRING_identification_context__negotiation(*this); }
  const TTCN_Typedescriptor_t* get_descriptor() const { return &CHARACTER_STRING_descr_; }
#else
  inline boolean is_present() const { return is_bound(); }
#endif
  void set_param(Module_Param& param);
  void encode_text(Text_Buf& text_buf) const;
  void decode_text(Text_Buf& text_buf);
  //void encode(const TTCN_Typedescriptor_t& p_td, TTCN_Buffer& p_buf, TTCN_EncDec::coding_t p_coding, ...) const;
  //void decode(const TTCN_Typedescriptor_t& p_td, TTCN_Buffer& p_buf, TTCN_EncDec::coding_t p_coding, ...);
  ASN_BER_TLV_t* BER_encode_TLV(const TTCN_Typedescriptor_t& p_td, unsigned p_coding) const;
  boolean BER_decode_TLV(const TTCN_Typedescriptor_t& p_td, const ASN_BER_TLV_t& p_tlv, unsigned L_form);
  int XER_encode(const XERdescriptor_t& p_td,
                 TTCN_Buffer& p_buf, unsigned int flavor, int indent) const;
  int XER_decode(const XERdescriptor_t& p_td,
                 XmlReaderWrap& reader, unsigned int flavor);
};

class CHARACTER_STRING_identification_context__negotiation_template : public Base_Template {
#ifdef __SUNPRO_CC
 public:
#endif
  struct single_value_struct;
#ifdef __SUNPRO_CC
 private:
#endif
  union {
    single_value_struct *single_value;
    struct {
      unsigned int n_values;
      CHARACTER_STRING_identification_context__negotiation_template *list_value;
    } value_list;
  };

  void set_specific();
  void copy_value(const CHARACTER_STRING_identification_context__negotiation& other_value);
  void copy_template(const CHARACTER_STRING_identification_context__negotiation_template& other_value);

public:
  CHARACTER_STRING_identification_context__negotiation_template();
  CHARACTER_STRING_identification_context__negotiation_template(template_sel other_value);
  CHARACTER_STRING_identification_context__negotiation_template(const CHARACTER_STRING_identification_context__negotiation& other_value);
  CHARACTER_STRING_identification_context__negotiation_template(const OPTIONAL<CHARACTER_STRING_identification_context__negotiation>& other_value);
  CHARACTER_STRING_identification_context__negotiation_template(const CHARACTER_STRING_identification_context__negotiation_template& other_value);
  ~CHARACTER_STRING_identification_context__negotiation_template();
  void clean_up();
  CHARACTER_STRING_identification_context__negotiation_template& operator=(template_sel other_value);
  CHARACTER_STRING_identification_context__negotiation_template& operator=(const CHARACTER_STRING_identification_context__negotiation& other_value);
  CHARACTER_STRING_identification_context__negotiation_template& operator=(const OPTIONAL<CHARACTER_STRING_identification_context__negotiation>& other_value);
  CHARACTER_STRING_identification_context__negotiation_template& operator=(const CHARACTER_STRING_identification_context__negotiation_template& other_value);
  boolean match(const CHARACTER_STRING_identification_context__negotiation& other_value) const;
  CHARACTER_STRING_identification_context__negotiation valueof() const;
  void set_type(template_sel template_type, unsigned int list_length);
  CHARACTER_STRING_identification_context__negotiation_template& list_item(unsigned int list_index) const;
  INTEGER_template& presentation__context__id();
  const INTEGER_template& presentation__context__id() const;
  OBJID_template& transfer__syntax();
  const OBJID_template& transfer__syntax() const;
  int size_of() const;
  void log() const;
  void log_match(const CHARACTER_STRING_identification_context__negotiation& match_value) const;
  void encode_text(Text_Buf& text_buf) const;
  void decode_text(Text_Buf& text_buf);

  boolean is_present() const;
  boolean match_omit() const;
  void set_param(Module_Param& param);
#ifdef TITAN_RUNTIME_2
  void valueofv(Base_Type* value) const { *(static_cast<CHARACTER_STRING_identification_context__negotiation*>(value)) = valueof(); }
  void set_value(template_sel other_value) { *this = other_value; }
  void copy_value(const Base_Type* other_value) { *this = *(static_cast<const CHARACTER_STRING_identification_context__negotiation*>(other_value)); }
  Base_Template* clone() const { return new CHARACTER_STRING_identification_context__negotiation_template(*this); }
  const TTCN_Typedescriptor_t* get_descriptor() const { return &CHARACTER_STRING_descr_; }
  boolean matchv(const Base_Type* other_value) const { return match(*(static_cast<const CHARACTER_STRING_identification_context__negotiation*>(other_value))); }
  void log_matchv(const Base_Type* match_value) const { log_match(*(static_cast<const CHARACTER_STRING_identification_context__negotiation*>(match_value))); }
#else
  void check_restriction(template_res t_res, const char* t_name=NULL) const;
#endif
};

/** Runtime class for ASN.1 unrestricted <tt>CHARACTER STRING</tt> type
 *
 */
class CHARACTER_STRING : public Base_Type {
  CHARACTER_STRING_identification field_identification;
  OPTIONAL<UNIVERSAL_CHARSTRING> field_data__value__descriptor;
  OCTETSTRING field_string__value;
public:
  CHARACTER_STRING();
  CHARACTER_STRING(const CHARACTER_STRING_identification& par_identification,
		   const OPTIONAL<UNIVERSAL_CHARSTRING>& par_data__value__descriptor,
		   const OCTETSTRING& par_string__value);
  boolean operator==(const CHARACTER_STRING& other_value) const;
  inline boolean operator!=(const CHARACTER_STRING& other_value) const
  { return !(*this == other_value); }

  inline CHARACTER_STRING_identification& identification()
  {return field_identification;}
  inline const CHARACTER_STRING_identification& identification() const
  {return field_identification;}
  inline OPTIONAL<UNIVERSAL_CHARSTRING>& data__value__descriptor()
  {return field_data__value__descriptor;}
  inline const OPTIONAL<UNIVERSAL_CHARSTRING>& data__value__descriptor() const
  {return field_data__value__descriptor;}
  inline OCTETSTRING& string__value()
  {return field_string__value;}
  inline const OCTETSTRING& string__value() const
  {return field_string__value;}
  boolean is_bound() const;
  boolean is_value() const;
  void clean_up();
  int size_of() const;
  void log() const;
#ifdef TITAN_RUNTIME_2
  boolean is_equal(const Base_Type* other_value) const { return *this == *(static_cast<const CHARACTER_STRING*>(other_value)); }
  void set_value(const Base_Type* other_value) { *this = *(static_cast<const CHARACTER_STRING*>(other_value)); }
  Base_Type* clone() const { return new CHARACTER_STRING(*this); }
  const TTCN_Typedescriptor_t* get_descriptor() const { return &CHARACTER_STRING_descr_; }
#else
  inline boolean is_present() const { return is_bound(); }
#endif
  void set_param(Module_Param& param);
  void encode_text(Text_Buf& text_buf) const;
  void decode_text(Text_Buf& text_buf);
  void encode(const TTCN_Typedescriptor_t& p_td, TTCN_Buffer& p_buf, TTCN_EncDec::coding_t p_coding, ...) const;
  void decode(const TTCN_Typedescriptor_t& p_td, TTCN_Buffer& p_buf, TTCN_EncDec::coding_t p_coding, ...);
  ASN_BER_TLV_t* BER_encode_TLV(const TTCN_Typedescriptor_t& p_td, unsigned p_coding) const;
  boolean BER_decode_TLV(const TTCN_Typedescriptor_t& p_td, const ASN_BER_TLV_t& p_tlv, unsigned L_form);
  int XER_encode(const XERdescriptor_t&, TTCN_Buffer&, unsigned int, int) const;
  int XER_decode(const XERdescriptor_t&, XmlReaderWrap& reader, unsigned int);
};

class CHARACTER_STRING_template : public Base_Template {
#ifdef __SUNPRO_CC
 public:
#endif
  struct single_value_struct;
#ifdef __SUNPRO_CC
 private:
#endif
  union {
    single_value_struct *single_value;
    struct {
      unsigned int n_values;
      CHARACTER_STRING_template *list_value;
    } value_list;
  };

  void set_specific();
  void copy_value(const CHARACTER_STRING& other_value);
  void copy_template(const CHARACTER_STRING_template& other_value);

public:
  CHARACTER_STRING_template();
  CHARACTER_STRING_template(template_sel other_value);
  CHARACTER_STRING_template(const CHARACTER_STRING& other_value);
  CHARACTER_STRING_template(const OPTIONAL<CHARACTER_STRING>& other_value);
  CHARACTER_STRING_template(const CHARACTER_STRING_template& other_value);
  ~CHARACTER_STRING_template();
  void clean_up();
  CHARACTER_STRING_template& operator=(template_sel other_value);
  CHARACTER_STRING_template& operator=(const CHARACTER_STRING& other_value);
  CHARACTER_STRING_template& operator=(const OPTIONAL<CHARACTER_STRING>& other_value);
  CHARACTER_STRING_template& operator=(const CHARACTER_STRING_template& other_value);
  boolean match(const CHARACTER_STRING& other_value) const;
  CHARACTER_STRING valueof() const;
  void set_type(template_sel template_type, unsigned int list_length);
  CHARACTER_STRING_template& list_item(unsigned int list_index) const;
  CHARACTER_STRING_identification_template& identification();
  const CHARACTER_STRING_identification_template& identification() const;
  UNIVERSAL_CHARSTRING_template& data__value__descriptor();
  const UNIVERSAL_CHARSTRING_template& data__value__descriptor() const;
  OCTETSTRING_template& string__value();
  const OCTETSTRING_template& string__value() const;
  int size_of() const;
  void log() const;
  void log_match(const CHARACTER_STRING& match_value) const;
  void encode_text(Text_Buf& text_buf) const;
  void decode_text(Text_Buf& text_buf);

  boolean is_present() const;
  boolean match_omit() const;
  void set_param(Module_Param& param);
#ifdef TITAN_RUNTIME_2
  void valueofv(Base_Type* value) const { *(static_cast<CHARACTER_STRING*>(value)) = valueof(); }
  void set_value(template_sel other_value) { *this = other_value; }
  void copy_value(const Base_Type* other_value) { *this = *(static_cast<const CHARACTER_STRING*>(other_value)); }
  Base_Template* clone() const { return new CHARACTER_STRING_template(*this); }
  const TTCN_Typedescriptor_t* get_descriptor() const { return &CHARACTER_STRING_descr_; }
  boolean matchv(const Base_Type* other_value) const { return match(*(static_cast<const CHARACTER_STRING*>(other_value))); }
  void log_matchv(const Base_Type* match_value) const  { log_match(*(static_cast<const CHARACTER_STRING*>(match_value))); }
#else
  void check_restriction(template_res t_res, const char* t_name=NULL) const;
#endif
};

#endif // ASN_CharacterString_HH
