#ifndef GLM_GTX_PRINT_H
#define GLM_GTX_PRINT_H

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

size_t glm_print_stream_bvec1(FILE *s, glm_bvec1 v)
{
	return fprintf(s, "bvec1(%s)", v.x ? "true" : "false");
}

size_t glm_print_stream_bvec2(FILE *s, glm_bvec2 v)
{
	return fprintf(s, "bvec2(%s, %s)", v.x ? "true" : "false", v.y ? "true" : "false");
}

size_t glm_print_stream_bvec3(FILE *s, glm_bvec3 v)
{
	return fprintf(s, "bvec3(%s, %s, %s)", v.x ? "true" : "false", v.y ? "true" : "false", v.z ? "true" : "false");
}

size_t glm_print_stream_bvec4(FILE *s, glm_bvec4 v)
{
	return fprintf(s, "bvec4(%s, %s, %s, %s)", v.x ? "true" : "false", v.y ? "true" : "false", v.z ? "true" : "false", v.w ? "true" : "false");
}

size_t glm_print_stream_vec1(FILE *s, glm_vec1 v)
{
	return fprintf(s, "vec1(%f)", v.x);
}

size_t glm_print_stream_vec2(FILE *s, glm_vec2 v)
{
	return fprintf(s, "vec2(%f, %f)", v.x, v.y);
}

size_t glm_print_stream_vec3(FILE *s, glm_vec3 v)
{
	return fprintf(s, "vec3(%f, %f, %f)", v.x, v.y, v.z);
}

size_t glm_print_stream_vec4(FILE *s, glm_vec4 v)
{
	return fprintf(s, "vec4(%f, %f, %f, %f)", v.x, v.y, v.z, v.w);
}

size_t glm_print_stream_dvec1(FILE *s, glm_dvec1 v)
{
	return fprintf(s, "dvec1(%lf)", v.x);
}

size_t glm_print_stream_dvec2(FILE *s, glm_dvec2 v)
{
	return fprintf(s, "dvec2(%lf, %lf)", v.x, v.y);
}

size_t glm_print_stream_dvec3(FILE *s, glm_dvec3 v)
{
	return fprintf(s, "dvec3(%lf, %lf, %lf)", v.x, v.y, v.z);
}

size_t glm_print_stream_dvec4(FILE *s, glm_dvec4 v)
{
	return fprintf(s, "dvec4(%lf, %lf, %lf, %lf)", v.x, v.y, v.z, v.w);
}

size_t glm_print_stream_ivec1(FILE *s, glm_ivec1 v)
{
	return fprintf(s, "ivec1(%d)", v.x);
}

size_t glm_print_stream_ivec2(FILE *s, glm_ivec2 v)
{
	return fprintf(s, "ivec2(%d, %d)", v.x, v.y);
}

size_t glm_print_stream_ivec3(FILE *s, glm_ivec3 v)
{
	return fprintf(s, "ivec3(%d, %d, %d)", v.x, v.y, v.z);
}

size_t glm_print_stream_ivec4(FILE *s, glm_ivec4 v)
{
	return fprintf(s, "ivec4(%d, %d, %d, %d)", v.x, v.y, v.z, v.w);
}

size_t glm_print_stream_uvec1(FILE *s, glm_uvec1 v)
{
	return fprintf(s, "uvec1(%u)", v.x);
}

size_t glm_print_stream_uvec2(FILE *s, glm_uvec2 v)
{
	return fprintf(s, "uvec2(%u, %u)", v.x, v.y);
}

size_t glm_print_stream_uvec3(FILE *s, glm_uvec3 v)
{
	return fprintf(s, "uvec3(%u, %u, %u)", v.x, v.y, v.z);
}

size_t glm_print_stream_uvec4(FILE *s, glm_uvec4 v)
{
	return fprintf(s, "uvec4(%u, %u, %u, %u)", v.x, v.y, v.z, v.w);
}

size_t glm_vfprint1(FILE *stream, const char *specifier, bool doExtra, const char *extra, va_list ap)
{
	if (extra)
	{

	}
	else
	{

	}
}


size_t glm_print_stream_va(FILE *stream, const char *format, va_list ap)
{
	size_t written = 0;
	const char *pchar = format;
	char specifier[16]; // Type identifier
	char extra[16];
	size_t tokenLen;
	const char *token;
	bool doExtra;
	char argFormat[64];

	while (*pchar != '\0')
	{
		if (*pchar == '{')
		{
			// Parse type from inside {}

			++pchar; // Consume '{'

			while (*pchar == ' ') ++pchar; // Consume all ' '

			token = pchar; // Set start of token
			while (*pchar != ' ' && *pchar != ':' && *pchar != '}') ++pchar;
			tokenLen = pchar - token;

			memcpy(specifier, token, tokenLen);
			specifier[tokenLen] = '\0';

			// Consume all ' '
			while (*pchar == ' ') ++pchar;

			if (*pchar == ':')
			{
				++pchar; // Consume '{'

				while (*pchar == ' ') ++pchar; // Consume all ' '

				token = pchar; // Set start of token
				while (*pchar != ' ' && *pchar != ':' && *pchar != '}') ++pchar;
				tokenLen = pchar - token;

				doExtra = (tokenLen > 0);

				if (doExtra)
				{
					memcpy(extra, token, tokenLen);
					extra[tokenLen] = '\0';
				}

				// Consume all ' '
				while (*pchar == ' ') ++pchar;

				// Expect '}' for end of specifier detail, consume '}'
				++pchar;
			}
			else
			{
				// Consume all ' '
				while (*pchar == ' ') ++pchar;

				// Expect '}' for end of specifier detail, consume '}'
				++pchar;
			}

			//printf(specifier);

			if (!strcmp(specifier, "b"))
			{
				bool v = (bool)va_arg(ap, int); // Fix implicit conversion
				fputs(v ? "true" : "false", stream);
			}
			else if (!strcmp(specifier, "f"))
			{
				float v = (double)va_arg(ap, double); // Fix implicit conversion

				if (doExtra) sprintf(argFormat, "%%%sf", extra);
				else strcpy(argFormat, "%f");

				fprintf(stream, argFormat, v);
			}
			else if (!strcmp(specifier, "lf"))
			{
				double v = va_arg(ap, double);

				if (doExtra) sprintf(argFormat, "%%%slf", extra);
				else strcpy(argFormat, "%lf");

				fprintf(stream, argFormat, v);
			}
			else if (!strcmp(specifier, "i"))
			{
				int v = va_arg(ap, int);

				if (doExtra) sprintf(argFormat, "%%%sd", extra);
				else strcpy(argFormat, "%i");

				fprintf(stream, argFormat, v);
			}
			else if (!strcmp(specifier, "u"))
			{
				unsigned int v = va_arg(ap, unsigned int);

				if (doExtra) sprintf(argFormat, "%%%su", extra);
				else strcpy(argFormat, "%u");

				fprintf(stream, argFormat, v);
			}
			else if (!strcmp(specifier, "bvec1"))
			{
				glm_bvec1 v = va_arg(ap, glm_bvec1);
				written += fprintf(stream, "bvec1(%s)", v.x ? "true" : "false");
			}
			else if (!strcmp(specifier, "bvec2"))
			{
				glm_bvec2 v = va_arg(ap, glm_bvec2);
				written += fprintf(stream, "bvec2(%s, %s)",
					v.x ? "true" : "false",
					v.y ? "true" : "false");
			}
			else if (!strcmp(specifier, "bvec3"))
			{
				glm_bvec3 v = va_arg(ap, glm_bvec3);
				written += fprintf(stream, "bvec3(%s, %s, %s)",
					v.x ? "true" : "false",
					v.y ? "true" : "false",
					v.z ? "true" : "false");
			}
			else if (!strcmp(specifier, "bvec4"))
			{
				glm_bvec4 v = va_arg(ap, glm_bvec4);
				written += fprintf(stream, "bvec4(%s, %s, %s, %s)",
					v.x ? "true" : "false",
					v.y ? "true" : "false",
					v.z ? "true" : "false",
					v.w ? "true" : "false");
			}
			else if (!strcmp(specifier, "vec1"))
			{
				glm_vec1 v = va_arg(ap, glm_vec1);

				if (doExtra)
					sprintf(argFormat, "vec1(%%%sf)", extra);
				else
					strcpy(argFormat, "vec1(%f)");

				written += fprintf(stream, argFormat, v.x);
			}
			else if (!strcmp(specifier, "vec2"))
			{
				glm_vec2 v = va_arg(ap, glm_vec2);

				if (doExtra)
					sprintf(argFormat, "vec2(%%%sf, %%%sf)", extra, extra);
				else
					strcpy(argFormat, "vec2(%f, %f)");

				written += fprintf(stream, argFormat, v.x, v.y);
			}
			else if (!strcmp(specifier, "vec3"))
			{
				glm_vec3 v = va_arg(ap, glm_vec3);

				if (doExtra)
					sprintf(argFormat, "vec3(%%%sf, %%%sf, %%%sf)", extra, extra, extra);
				else
					strcpy(argFormat, "vec3(%f, %f, %f)");

				written += fprintf(stream, argFormat, v.x, v.y, v.z);
			}
			else if (!strcmp(specifier, "vec4"))
			{
				glm_vec4 v = va_arg(ap, glm_vec4);

				if (doExtra)
					sprintf(argFormat, "vec4(%%%sf, %%%sf, %%%sf, %%%sf)", extra, extra, extra, extra);
				else
					strcpy(argFormat, "vec4(%f, %f, %f, %f)");

				written += fprintf(stream, argFormat, v.x, v.y, v.z, v.w);
			}
			else if (!strcmp(specifier, "dvec1"))
			{
				glm_dvec1 v = va_arg(ap, glm_dvec1);

				if (doExtra)
					sprintf(argFormat, "dvec1(%%%slf)", extra);
				else
					strcpy(argFormat, "dvec1(%lf)");

				written += fprintf(stream, argFormat, v.x);
			}
			else if (!strcmp(specifier, "dvec2"))
			{
				glm_dvec2 v = va_arg(ap, glm_dvec2);

				if (doExtra)
					sprintf(argFormat, "dvec2(%%%slf, %%%slf)", extra, extra);
				else
					strcpy(argFormat, "dvec2(%lf, %lf)");

				written += fprintf(stream, argFormat, v.x, v.y);
			}
			else if (!strcmp(specifier, "dvec3"))
			{
				glm_dvec3 v = va_arg(ap, glm_dvec3);

				if (doExtra)
					sprintf(argFormat, "dvec3(%%%slf, %%%slf, %%%slf)", extra, extra, extra);
				else
					strcpy(argFormat, "dvec3(%lf, %lf, %lf)");

				written += fprintf(stream, argFormat, v.x, v.y, v.z);
			}
			else if (!strcmp(specifier, "dvec4"))
			{
				glm_dvec4 v = va_arg(ap, glm_dvec4);

				if (doExtra)
					sprintf(argFormat, "dvec4(%%%slf, %%%slf, %%%slf, %%%slf)", extra, extra, extra, extra);
				else
					strcpy(argFormat, "dvec4(%lf, %lf, %lf, %lf)");

				written += fprintf(stream, argFormat, v.x, v.y, v.z, v.w);
			}
			else if (!strcmp(specifier, "ivec1"))
			{
				glm_ivec1 v = va_arg(ap, glm_ivec1);

				if (doExtra)
					sprintf(argFormat, "ivec1(%%%si)", extra);
				else
					strcpy(argFormat, "ivec1(%i)");

				written += fprintf(stream, argFormat, v.x);
			}
			else if (!strcmp(specifier, "ivec2"))
			{
				glm_ivec2 v = va_arg(ap, glm_ivec2);

				if (doExtra)
					sprintf(argFormat, "ivec2(%%%si, %%%si)", extra, extra);
				else
					strcpy(argFormat, "ivec2(%i, %i)");

				written += fprintf(stream, argFormat, v.x, v.y);
			}
			else if (!strcmp(specifier, "ivec3"))
			{
				glm_ivec3 v = va_arg(ap, glm_ivec3);

				if (doExtra)
					sprintf(argFormat, "ivec3(%%%si, %%%si, %%%si)", extra, extra, extra);
				else
					strcpy(argFormat, "ivec3(%i, %i, %i)");

				written += fprintf(stream, argFormat, v.x, v.y, v.z);
			}
			else if (!strcmp(specifier, "ivec4"))
			{
				glm_ivec4 v = va_arg(ap, glm_ivec4);

				if (doExtra)
					sprintf(argFormat, "ivec4(%%%si, %%%si, %%%si, %%%si)", extra, extra, extra, extra);
				else
					strcpy(argFormat, "ivec4(%i, %i, %i, %i)");

				written += fprintf(stream, argFormat, v.x, v.y, v.z, v.w);
			}
			else if (!strcmp(specifier, "uvec1"))
			{
				glm_uvec1 v = va_arg(ap, glm_uvec1);

				if (doExtra)
					sprintf(argFormat, "uvec1(%%%su)", extra);
				else
					strcpy(argFormat, "uvec1(%u)");

				written += fprintf(stream, argFormat, v.x);
			}
			else if (!strcmp(specifier, "uvec2"))
			{
				glm_uvec2 v = va_arg(ap, glm_uvec2);

				if (doExtra)
					sprintf(argFormat, "uvec2(%%%su, %%%su)", extra, extra);
				else
					strcpy(argFormat, "uvec2(%u, %u)");

				written += fprintf(stream, argFormat, v.x, v.y);
			}
			else if (!strcmp(specifier, "uvec3"))
			{
				glm_uvec3 v = va_arg(ap, glm_uvec3);

				if (doExtra)
					sprintf(argFormat, "uvec3(%%%su, %%%su, %%%su)", extra, extra, extra);
				else
					strcpy(argFormat, "uvec3(%u, %u, %u)");

				written += fprintf(stream, argFormat, v.x, v.y, v.z);
			}
			else if (!strcmp(specifier, "uvec4"))
			{
				glm_uvec4 v = va_arg(ap, glm_uvec4);

				if (doExtra)
					sprintf(argFormat, "uvec4(%%%su, %%%su, %%%su, %%%su)", extra, extra, extra, extra);
				else
					strcpy(argFormat, "uvec4(%u, %u, %u, %u)");

				written += fprintf(stream, argFormat, v.x, v.y, v.z, v.w);
			}
		}

		putc(*pchar, stream);
		++pchar;
		++written;
	}

	return written;
}

size_t glm_print(const char *format, ...)
{
	va_list ap;
	va_start(ap, format);

	size_t written = glm_print_stream_va(stdout, format, ap);

	va_end(ap);
	return written;
}

/*
void glm_fprintf(FILE *s, glm_type_t type, ...)
{
	va_list ap;
	va_start(ap, type);

	switch (type)
	{
		case GLM_TYPE_BOOL1:
			glm_fprint_bvec1(s, va_arg(ap, glm_bvec1));
			break;
		case GLM_TYPE_BOOL2:
			glm_fprint_bvec2(s, va_arg(ap, glm_bvec2));
			break;
		case GLM_TYPE_BOOL3: glm_fprint_bvec3(s, va_arg(ap, glm_bvec3));
			break;
		case GLM_TYPE_BOOL4: glm_fprint_bvec4(s, va_arg(ap, glm_bvec4));
			break;
		case GLM_TYPE_FLOAT1: glm_fprint_vec1(s, va_arg(ap, glm_vec1));
			break;
		case GLM_TYPE_FLOAT2: glm_fprint_vec2(s, va_arg(ap, glm_vec2));
			break;
		case GLM_TYPE_FLOAT3: glm_fprint_vec3(s, va_arg(ap, glm_vec3));
			break;
		case GLM_TYPE_FLOAT4: glm_fprint_vec4(s, va_arg(ap, glm_vec4));
			break;
		case GLM_TYPE_DOUBLE1: glm_fprint_dvec1(s, va_arg(ap, glm_dvec1));
			break;
		case GLM_TYPE_DOUBLE2: glm_fprint_dvec2(s, va_arg(ap, glm_dvec2));
			break;
		case GLM_TYPE_DOUBLE3: glm_fprint_dvec3(s, va_arg(ap, glm_dvec3));
			break;
		case GLM_TYPE_DOUBLE4: glm_fprint_dvec4(s, va_arg(ap, glm_dvec4));
			break;
		case GLM_TYPE_INT1: glm_fprint_ivec1(s, va_arg(ap, glm_ivec1));
			break;
		case GLM_TYPE_INT2: glm_fprint_ivec2(s, va_arg(ap, glm_ivec2));
			break;
		case GLM_TYPE_INT3: glm_fprint_ivec3(s, va_arg(ap, glm_ivec3));
			break;
		case GLM_TYPE_INT4: glm_fprint_ivec4(s, va_arg(ap, glm_ivec4));
			break;
		case GLM_TYPE_UINT1: glm_fprint_uvec1(s, va_arg(ap, glm_uvec1));
			break;
		case GLM_TYPE_UINT2: glm_fprint_uvec2(s, va_arg(ap, glm_uvec2));
			break;
		case GLM_TYPE_UINT3: glm_fprint_uvec3(s, va_arg(ap, glm_uvec3));
			break;
		case GLM_TYPE_UINT4: glm_fprint_uvec4(s, va_arg(ap, glm_uvec4));
			break;
	}

	va_end(ap);
}
*/
#endif /* GLM_GTX_PRINT_H */