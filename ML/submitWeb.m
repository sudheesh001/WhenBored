function submitWeb(partId)
  if ~exist('partId', 'var') || isempty(partId)
    partId = [];
  end
  
  submit(partId, 1);
end

