#ifndef GLM_DETAIL_TYPE_MATRIX_IMPL_H
#define GLM_DETAIL_TYPE_MATRIX_IMPL_H

#include "namespace_begin.inl"
#include "namespace_template_matrix_begin.inl"

#define C 2
#define R 2
#define T float
#define Q defaultp
#include "type_matrix.inl"
#undef C
#undef R
#undef T
#undef Q

#define C 2
#define R 3
#define T float
#define Q defaultp
#include "type_matrix.inl"
#undef C
#undef R
#undef T
#undef Q


#define C 2
#define R 4
#define T float
#define Q defaultp
#include "type_matrix.inl"
#undef C
#undef R
#undef T
#undef Q


#define C 3
#define R 2
#define T float
#define Q defaultp
#include "type_matrix.inl"
#undef C
#undef R
#undef T
#undef Q


#define C 3
#define R 3
#define T float
#define Q defaultp
#include "type_matrix.inl"
#undef C
#undef R
#undef T
#undef Q


#define C 3
#define R 4
#define T float
#define Q defaultp
#include "type_matrix.inl"
#undef C
#undef R
#undef T
#undef Q


#define C 4
#define R 2
#define T float
#define Q defaultp
#include "type_matrix.inl"
#undef C
#undef R
#undef T
#undef Q


#define C 4
#define R 3
#define T float
#define Q defaultp
#include "type_matrix.inl"
#undef C
#undef R
#undef T
#undef Q


#define C 4
#define R 4
#define T float
#define Q defaultp
#include "type_matrix.inl"
#undef C
#undef R
#undef T
#undef Q

#include "namespace_template_matrix_end.inl"
#include "namespace_end.inl"

#endif /* GLM_DETAIL_TYPE_MATRIX_IMPL_H */