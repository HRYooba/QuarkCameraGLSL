uniform float u_TEMP_MAX;
uniform float u_time;
uniform sampler2DRect u_camera0;
uniform sampler2DRect u_camera1;
uniform sampler2DRect u_camera2;
uniform sampler2DRect u_camera3;
uniform sampler2DRect u_camera4;
uniform sampler2DRect u_camera5;
uniform sampler2DRect u_camera6;
uniform sampler2DRect u_camera7;
uniform sampler2DRect u_camera8;
uniform sampler2DRect u_camera9;
uniform sampler2DRect u_camera10;
uniform sampler2DRect u_camera11;
uniform sampler2DRect u_camera12;
uniform sampler2DRect u_camera13;
uniform sampler2DRect u_camera14;
uniform sampler2DRect u_camera15;

float rand(vec2 co) {
    return fract(sin(dot(co.xy ,vec2(12.9898,78.233))) * 43758.5453  * u_time);
}

void main() {
    vec2 pos = gl_FragCoord.xy;
    
    int random = int(rand(pos) * u_TEMP_MAX);
    
    vec4 camera0 = texture2DRect(u_camera0, pos);
    vec4 camera1 = texture2DRect(u_camera1, pos);
    vec4 camera2 = texture2DRect(u_camera2, pos);
    vec4 camera3 = texture2DRect(u_camera3, pos);
    vec4 camera4 = texture2DRect(u_camera4, pos);
    vec4 camera5 = texture2DRect(u_camera5, pos);
    vec4 camera6 = texture2DRect(u_camera6, pos);
    vec4 camera7 = texture2DRect(u_camera7, pos);
    vec4 camera8 = texture2DRect(u_camera8, pos);
    vec4 camera9 = texture2DRect(u_camera9, pos);
    vec4 camera10 = texture2DRect(u_camera10, pos);
    vec4 camera11 = texture2DRect(u_camera11, pos);
    vec4 camera12 = texture2DRect(u_camera12, pos);
    vec4 camera13 = texture2DRect(u_camera13, pos);
    vec4 camera14 = texture2DRect(u_camera14, pos);
    vec4 camera15 = texture2DRect(u_camera15, pos);
    
    vec4 col = vec4(0.0);
    
    if (random == 0) {
        col = camera0;
    } else if (random == 1) {
        col = camera1;
    } else if (random == 2) {
        col = camera2;
    } else if (random == 3) {
        col = camera3;
    } else if (random == 4) {
        col = camera4;
    } else if (random == 5) {
        col = camera5;
    } else if (random == 6) {
        col = camera6;
    } else if (random == 7) {
        col = camera7;
    } else if (random == 8) {
        col = camera8;
    } else if (random == 9) {
        col = camera9;
    } else if (random == 10) {
        col = camera10;
    } else if (random == 11) {
        col = camera11;
    } else if (random == 12) {
        col = camera12;
    } else if (random == 13) {
        col = camera13;
    } else if (random == 14) {
        col = camera14;
    } else if (random == 15) {
        col = camera15;
    }
    
    
    gl_FragColor = col;
}