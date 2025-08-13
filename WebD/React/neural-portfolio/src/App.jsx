import { useState } from 'react';
import Brain from './components/Brain';
import { neuronData } from './data/neuronData';

export default function App() {
  const [year, setYear] = useState(1);
  const [typeFilter, setTypeFilter] = useState('all');
  const [zoneFilter, setZoneFilter] = useState('all');

  const counts = neuronData.reduce((acc, n) => {
    acc[n.type] = (acc[n.type] || 0) + 1;
    return acc;
  }, {});

  return (
    <>
      <div className="skill-panel">
        <div className="mb-2 font-bold text-white">Skill Map</div>
        {['language', 'tool', 'project', 'achievement', 'milestone'].map((t) => (
          <div
            key={t}
            onClick={() => setTypeFilter(t)}
            className={`cursor-pointer px-2 py-1 mb-1 rounded flex justify-between ${
              typeFilter === t ? 'bg-white text-black' : 'bg-white/10 hover:bg-white/20'
            }`}
          >
            <span>{t.charAt(0).toUpperCase() + t.slice(1)}</span>
            <span className="opacity-70">({counts[t] || 0})</span>
          </div>
        ))}

        <button
          onClick={() => setTypeFilter('all')}
          className="mt-2 text-xs underline text-gray-300 hover:text-white"
        >
          Reset Filter
        </button>
      </div>

      <Brain year={year} typeFilter={typeFilter} zoneFilter={zoneFilter} />
    </>
  );
}
