uniform float t;
uniform int screenWidth;
uniform int screenHeight;

float calc(float n) {
    float sine = sin(n * n / 8.0 - t);
    return sine * sine;
}

void main() {
    float width = float(screenWidth) / 2.0;
    float height = float(screenHeight) / 2.0;
    float x = float(int(abs(gl_TexCoord[0].x * width - width / 2.0)));
    float y = float(int(abs(gl_TexCoord[0].y * height - height / 2.0)));
    vec3 color = vec3(calc(sqrt(x * x + y * y)));
    color *= vec3(0.2, 0.1, 0.025);
    if (color.x > 0.16) {
        color.x = 0.16;
    } else {
        color.x = 0.0;
    }
    if (color.y > 0.08) {
        color.y = 0.08;
    } else {
        color.y = 0.0;
    }
    if (color.z > 0.02) {
        color.z = 0.02;
    } else {
        color.z = 0.0;
    }
    gl_FragColor = vec4(color, 1);
}