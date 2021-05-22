uniform float t;
uniform int screenWidth;
uniform int screenHeight;

float calcR(float n) {
    n /= float(screenWidth);
    return (sin(t + n) + 1.0) / 16.0;
}

float calcG(float n) {
    n /= float(screenWidth);
    return (sin(t + n) + 1.0) / 16.0;
}

float calcB(float n) {
    n /= float(screenWidth);
    return (sin(t + n) + 1.0) / 16.0;
}

void main() {
    float x = gl_TexCoord[0].x * float(screenWidth);
    float y = gl_TexCoord[0].y * float(screenHeight);
    vec3 color = vec3(calcR(x * (float(screenHeight) - y)), calcG(y * (float(screenWidth) - x)), calcB(x * y));
    gl_FragColor = vec4(color, 1);
}