

#version 410
in vec2 tc;
out vec4 color;
in float alpha_r;
in float alpha_g;
in float alpha_b;
in float current_index;
in float timeval;

uniform mat4 mv_matrix;
uniform mat4 proj_matrix;
uniform sampler2D samp;
uniform float value_alpha_r, value_alpha_g, value_alpha_b;
uniform float index_value;
uniform float time_f;



void main(void)
{
    color = texture(samp, tc);
    ivec3 source;
    for(int i = 0; i < 3; ++i) {
        source[i] = int(255 * color[i]);
    }
    
    color[0] += tc[0];
    color[1] += tc[1];
    color[2] += tc[0]+tc[1];
    
    color[0] += 0.1*timeval;
    color[1] += 0.3*timeval;
    color[2] += 0.7*timeval;
    
    ivec3 int_color;
    for(int i = 0; i < 3; ++i) {
        int_color[i] = int(255 * color[i]);
        int_color[i] = int_color[i]^source[i];
        int_color[i] = int_color[i]%255;
        color[i] = float(int_color[i])/255;
    }
}