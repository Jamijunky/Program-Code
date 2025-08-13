export const neuronData = [
  {
    id: 'html',
    pos: [1, 2, -2],
    color: '#f97316',
    label: 'HTML',
    story: 'The first building block I learned in web development.',
    projects: ['Personal Website'],
    type: 'language',
    connections: ['css']
  },
  {
    id: 'css',
    pos: [-2, 1, 1],
    color: '#0ea5e9',
    label: 'CSS',
    story: 'I learned how to style the web.',
    projects: [],
    type: 'tool',
    connections: ['react']
  },
  {
    id: 'react',
    pos: [2, -1, 1],
    color: '#22d3ee',
    label: 'React',
    story: 'React changed how I build things.',
    projects: ['Neural Doodle Pad'],
    type: 'tool',
    connections: ['tailwind']
  },
  {
    id: 'tailwind',
    pos: [0, 0, 3],
    color: '#38bdf8',
    label: 'Tailwind',
    story: 'Fast UI development.',
    projects: ['Portfolio UI'],
    type: 'tool',
    connections: []
  }
];