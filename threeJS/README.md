# HOW ABOUT THREE.JS

## Set up camera

```Javascript
const camera = new THREE.PerspectiveCamera(
75,                     // Field of View (FOV) in degrees
window.innerWidth / window.innerHeight,  // Aspect ratio
0.1,                    // Near clipping plane distance
1000                    // Far clipping plane distance
);
```

Perspective camera  -> Near | Object (move) | -> Far  : Zoom in/out  