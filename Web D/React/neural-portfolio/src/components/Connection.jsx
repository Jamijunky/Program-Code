import { Line } from '@react-three/drei';

export default function Connection({ from, to }) {
  if (!from || !to) return null;
  return (
    <Line
      points={[from, to]}
      color="white"
      lineWidth={1}
      dashed
      dashSize={0.1}
      gapSize={0.1}
      transparent
      opacity={0.6}
    />
  );
}