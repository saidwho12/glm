#include <stdio.h>
#include <stdlib.h>

#include <glm/glm.h>
#include <glm/gtx/print.h>

int main(int argc, char *argv[])
{
    glm_vec2 v1 = { 2.63f, 8.54f };
    glm_vec2 v2 = { 1.81f, 11.2f };
    
    glm_bvec2 v3 = glm_lessThan(v1, v2);
    
    glm_print("{vec2} < {vec2} = {bvec2}\n\n", v1, v2, v3);
    
    glm_bvec2 v4 = glm_not(v3);
    
    glm_print("!{bvec2} = {bvec2}\n\n", v3, v4);
    
    glm_bvec4 v5 = glm_bvec4(v3, v4);
    
    glm_print("bvec4({bvec2}, {bvec2}) -> {bvec4}\n\n", v3, v4, v5);
    
    glm_bvec4 v6 = { true, true, false, false };
    
    glm_bvec4 v7 = glm_and(v5, v6);
    
    glm_print("{bvec4} && {bvec4} = {bvec4}\n\n", v5, v6, v7);
    
    bool b1 = glm_any(glm_not(v7));
    
    glm_print("any(!{bvec4}) = {b}\n\n", v7, b1);
    
    bool g2;
    
	return EXIT_SUCCESS;
}