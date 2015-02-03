uniform sampler2D texture;
uniform float time;

void main()
{
    const float freq = 0.1;
    const float lambda = 0.5;
    float amplitude = 0.02;
    // lookup the pixel in the texture
    vec2 offset = vec2(amplitude*sin(6.28*(gl_TexCoord[0].y-freq*time)/lambda),0);
    vec4 pixel = texture2D(texture, gl_TexCoord[0].xy+offset.xy);

    // multiply it by the color
    vec4 color = gl_Color;
    //color.a = 1-amplitude;
    gl_FragColor = color * pixel;
}
