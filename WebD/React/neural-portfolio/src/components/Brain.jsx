import { Canvas } from '@react-three/fiber';
import Neuron from './Neuron';
import Connection from './Connection';
import { neuronData } from '../data/neuronData';
import { Suspense, useState } from 'react';

export default function Brain({ year, typeFilter, zoneFilter }) {
  const [activeNeuronId, setActiveNeuronId] = useState(null);

  const visibleNeurons = neuronData.filter((n) => {
    if (typeFilter !== 'all' && n.type !== typeFilter) return false;
    if (zoneFilter !== 'all' && n.zone !== zoneFilter) return false;
    return true;
  });

  return (
    <Canvas camera={{ position: [0, 0, 8], fov: 50 }} style={{ height: '100vh' }} shadows>
      <ambientLight intensity={0.5} />
      <pointLight position={[10, 10, 10]} intensity={1} castShadow />
      <Suspense fallback={null}>
        {visibleNeurons.map((n) => {
          const isActive = n.id === activeNeuronId;
          const isConnected =
            activeNeuronId &&
            neuronData.find((node) => node.id === activeNeuronId)?.connections.includes(n.id);

          const faded = activeNeuronId && !isActive && !isConnected;

          return (
            <Neuron
              key={n.id}
              position={n.pos}
              color={n.color}
              label={n.label}
              story={n.story}
              projects={n.projects}
              type={n.type}
              isFaded={faded}
              isHighlighted={isActive || isConnected}
              onClick={() => setActiveNeuronId((prev) => (prev === n.id ? null : n.id))}
            />
          );
        })}

        {neuronData.map((fromNeuron) =>
          fromNeuron.connections.map((targetId) => {
            const toNeuron = neuronData.find((n) => n.id === targetId);
            return (
              <Connection
                key={`${fromNeuron.id}-${targetId}`}
                from={fromNeuron.pos}
                to={toNeuron?.pos}
              />
            );
          })
        )}
      </Suspense>
    </Canvas>
  );
}
