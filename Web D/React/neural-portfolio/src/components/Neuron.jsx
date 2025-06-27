import { useRef, useState } from 'react';
import { animated, useSpring } from '@react-spring/three';
import { Text } from '@react-three/drei';

export default function Neuron({
  position,
  color,
  label,
  story,
  projects,
  isFaded,
  isHighlighted,
  onClick
}) {
  const mesh = useRef();
  const [hovered, setHovered] = useState(false);

  const { scale, opacity } = useSpring({
    scale: isHighlighted ? 1.5 : hovered ? 1.2 : 1,
    opacity: 1,
    config: { mass: 1, tension: 200, friction: 20 }
  });

  return (
    <animated.mesh
      ref={mesh}
      position={position}
      scale={scale}
      onClick={onClick}
      onPointerOver={() => setHovered(true)}
      onPointerOut={() => setHovered(false)}
    >
      <sphereGeometry args={[0.3, 32, 32]} />
      <animated.meshStandardMaterial
        color={color}
        emissive={color}
        emissiveIntensity={isHighlighted ? 1.5 : hovered ? 0.8 : 0.1}
        transparent
        opacity={opacity.to((o) => (isFaded ? o * 0.15 : o))}
      />
      <Text
        position={[0, 0.6, 0]}
        fontSize={0.3}
        color={isHighlighted ? 'white' : '#ccc'}
        anchorX="center"
        anchorY="middle"
        className="neuron-label"
        depthOffset={-1}
      >
        {label}
      </Text>
    </animated.mesh>
  );
}
